/*
-- WORKING PRINCIPLE --
This program implements a binary search tree (BST) with an operation to remove a node by its key.
The program ensures that the tree remains a valid BST after the deletion.
The `remove` function searches for the node by its key and then deletes it while maintaining the BST property.
The helper function `find_min` is used to find the minimum key node in a given subtree.

-- PROOF OF CORRECTNESS --
The `remove` function ensures that the tree remains a valid BST in several steps:
1. It recursively searches for the node to be deleted.
2. If the node has zero or one child, it deletes the node and returns the non-null child, if any.
3. If the node has two children, it finds the in-order successor (minimum node in the right subtree), replaces the
 node's key with that of the successor, and then recursively deletes the successor.
By these operations, the BST property is maintained at every step.

-- TIME COMPLEXITY --
The time complexity for the `remove` operation is `O(h)` where `h` is the height of the tree.
This is because in the worst case, we might have to traverse from the root node to a leaf node.

-- SPACE COMPLEXITY --
The space complexity is `O(1)` for the `remove` function as it operates in-place and doesn't use any additional data
 structures.
*/

use std::cell::RefCell;
use std::cmp::Ordering;
use std::rc::Rc;

type NodePtr<T> = Option<Rc<RefCell<Node<T>>>>;

pub struct Node<T> {
    value: T,
    left: NodePtr<T>,
    right: NodePtr<T>,
}

impl<T> Node<T> {
    pub fn new(
        left: Option<Rc<RefCell<Node<T>>>>,
        right: Option<Rc<RefCell<Node<T>>>>,
        value: T,
    ) -> Self {
        Self { value, left, right }
    }
}

fn find_min(mut root: NodePtr<i32>) -> NodePtr<i32> {
    while let Some(node) = root.clone() {
        if node.borrow().left.is_some() {
            root = node.borrow().left.clone();
        } else {
            break;
        }
    }
    root
}

pub fn remove(root: NodePtr<i32>, key: i32) -> NodePtr<i32> {
    let node = match root {
        Some(node) => node,
        None => return None,
    };

    let mut node_ref = node.borrow_mut();

    match key.cmp(&node_ref.value) {
        Ordering::Less => {
            node_ref.left = remove(node_ref.left.clone(), key);
        }
        Ordering::Greater => {
            node_ref.right = remove(node_ref.right.clone(), key);
        }
        Ordering::Equal => {
            let (left, right) = { (node_ref.left.clone(), node_ref.right.clone()) };
            if left.is_none() {
                return right;
            } else if right.is_none() {
                return left;
            }

            let temp = find_min(right.clone()).unwrap();
            {
                node_ref.value = temp.borrow().value;
                node_ref.right = remove(right, temp.borrow().value);
            }
        }
    }
    drop(node_ref);

    Some(node)
}

#[cfg(test)]
mod tests {
    use super::{remove, Node};
    use std::cell::RefCell;
    use std::rc::Rc;
    #[test]
    fn test() {
        let node1 = Rc::new(RefCell::new(Node::new(None, None, 2)));
        let node2 = Rc::new(RefCell::new(Node::new(Some(node1.clone()), None, 3)));
        let node3 = Rc::new(RefCell::new(Node::new(None, Some(node2.clone()), 1)));
        let node4 = Rc::new(RefCell::new(Node::new(None, None, 6)));
        let node5 = Rc::new(RefCell::new(Node::new(Some(node4.clone()), None, 8)));
        let node6 = Rc::new(RefCell::new(Node::new(Some(node5.clone()), None, 10)));
        let node7 = Rc::new(RefCell::new(Node::new(
            Some(node3.clone()),
            Some(node6.clone()),
            5,
        )));

        let new_head = remove(Some(node7.clone()), 10);

        assert_eq!(new_head.as_ref().unwrap().borrow().value, 5);
        assert!(Rc::ptr_eq(
            &new_head.as_ref().unwrap().borrow().right.as_ref().unwrap(),
            &node5
        ));
        assert_eq!(
            new_head
                .as_ref()
                .unwrap()
                .borrow()
                .right
                .as_ref()
                .unwrap()
                .borrow()
                .value,
            8
        );
    }
}
