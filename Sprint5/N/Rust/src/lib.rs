// https://contest.yandex.ru/contest/24809/problems/N/

use std::cell::RefCell;
use std::rc::Rc;

type NodePtr<T> = Option<Rc<RefCell<Node<T>>>>;

pub struct Node<T> {
    left: NodePtr<T>,
    right: NodePtr<T>,
    _value: T,
    size: usize,
}

impl<T> Node<T> {
    pub fn new(
        left: Option<Rc<RefCell<Node<T>>>>,
        right: Option<Rc<RefCell<Node<T>>>>,
        value: T,
        size: usize,
    ) -> Self {
        Self {
            left,
            right,
            _value: value,
            size,
        }
    }

    pub fn get_size(node: NodePtr<T>) -> usize {
        if let Some(node) = node {
            return node.borrow().size;
        }

        0
    }
}

pub fn split(root: NodePtr<i32>, k: usize) -> (NodePtr<i32>, NodePtr<i32>) {
    if let Some(node) = root {
        let mut node_borrow = node.borrow_mut();

        let l_size = Node::get_size(node_borrow.left.clone());
        let r_size = Node::get_size(node_borrow.right.clone());
        if l_size + 1 > k {
            let (left, left_side) = split(node_borrow.left.clone(), k);

            node_borrow.size = node_borrow.size - l_size + Node::get_size(left_side.clone());
            node_borrow.left = left_side;

            return (left, Some(node.clone()));
        }

        let (right, right_side) = split(node_borrow.right.clone(), k - (l_size + 1));

        node_borrow.size = node_borrow.size - r_size + Node::get_size(right.clone());
        node_borrow.right = right;

        return (Some(node.clone()), right_side);
    }

    (None, None)
}

#[cfg(test)]
mod tests {
    use super::{split, Node};
    use std::cell::RefCell;
    use std::rc::Rc;
    #[test]
    fn test() {
        let node1 = Rc::from(RefCell::new(Node::new(None, None, 3, 1)));
        let node2 = Rc::new(RefCell::new(Node::new(None, Some(node1), 2, 2)));
        let node3 = Rc::new(RefCell::new(Node::new(None, None, 8, 1)));
        let node4 = Rc::new(RefCell::new(Node::new(None, None, 11, 1)));
        let node5 = Rc::new(RefCell::new(Node::new(Some(node3), Some(node4), 10, 3)));
        let node6 = Rc::new(RefCell::new(Node::new(Some(node2), Some(node5), 5, 6)));

        let res = split(Some(node6), 4);
        assert_eq!(res.0.unwrap().borrow().size, 4);
        assert_eq!(res.1.unwrap().borrow().size, 2);
    }
}
