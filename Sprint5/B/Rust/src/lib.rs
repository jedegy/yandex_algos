// https://contest.yandex.ru/contest/24809/problems/B/

use std::cell::RefCell;
use std::rc::Rc;

type NodePtr<T> = Option<Rc<RefCell<Node<T>>>>;

pub struct Node<T> {
    _value: T,
    left: NodePtr<T>,
    right: NodePtr<T>,
}

impl<T> Node<T> {
    pub fn new(
        value: T,
        left: Option<Rc<RefCell<Node<T>>>>,
        right: Option<Rc<RefCell<Node<T>>>>,
    ) -> Self {
        Self {
            _value: value,
            left,
            right,
        }
    }
}

fn is_balanced(root: NodePtr<i32>, height: &mut usize) -> bool {
    if root.is_none() {
        *height = 0;
        return true;
    }

    let mut left_subtree_height = 0;
    let mut right_subtree_height = 0;
    let root_ref = root.unwrap();

    let left_subtree_balanced =
        is_balanced(root_ref.borrow().left.clone(), &mut left_subtree_height);
    let right_subtree_balanced =
        is_balanced(root_ref.borrow().right.clone(), &mut right_subtree_height);

    *height = std::cmp::max(left_subtree_height, right_subtree_height) + 1;

    left_subtree_balanced
        && right_subtree_balanced
        && (left_subtree_height as isize - right_subtree_height as isize).abs() <= 1
}

pub fn solution(root: NodePtr<i32>) -> bool {
    let mut height = 0;
    is_balanced(root, &mut height)
}

#[cfg(test)]
mod tests {
    use super::{solution, Node};
    use std::cell::RefCell;
    use std::rc::Rc;

    #[test]
    fn test() {
        let node1 = Rc::from(RefCell::new(Node::new(1, None, None)));
        let node2 = Rc::from(RefCell::new(Node::new(-5, None, None)));
        let node3 = Rc::from(RefCell::new(Node::new(3, Some(node1), Some(node2))));
        let node4 = Rc::from(RefCell::new(Node::new(10, None, None)));
        let node5 = Rc::from(RefCell::new(Node::new(3, Some(node3), Some(node4))));

        assert!(solution(Some(node5)));
    }
}
