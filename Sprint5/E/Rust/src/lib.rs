// https://contest.yandex.ru/contest/24809/problems/E/

use std::cell::RefCell;
use std::rc::Rc;

type NodePtr<T> = Option<Rc<RefCell<Node<T>>>>;

pub struct Node<T> {
    value: T,
    left: NodePtr<T>,
    right: NodePtr<T>,
}

impl<T> Node<T> {
    pub fn new(
        value: T,
        left: Option<Rc<RefCell<Node<T>>>>,
        right: Option<Rc<RefCell<Node<T>>>>,
    ) -> Self {
        Self { value, left, right }
    }
}

fn is_binary_search_tree(root: NodePtr<i32>, min: i32, max: i32) -> bool {
    if let Some(root) = root {
        if root.borrow().value <= min || root.borrow().value >= max {
            return false;
        }

        return is_binary_search_tree(root.borrow().left.clone(), min, root.borrow().value)
            && is_binary_search_tree(root.borrow().right.clone(), root.borrow().value, max);
    }

    true
}

pub fn solution(root: NodePtr<i32>) -> bool {
    is_binary_search_tree(root, i32::MIN, i32::MAX)
}

#[cfg(test)]
mod tests {
    use super::{solution, Node};
    use std::cell::RefCell;
    use std::rc::Rc;

    #[test]
    fn test() {
        let node1 = Rc::from(RefCell::new(Node::new(1, None, None)));
        let node2 = Rc::from(RefCell::new(Node::new(4, None, None)));
        let node3 = Rc::from(RefCell::new(Node::new(3, Some(node1), Some(node2))));
        let node4 = Rc::from(RefCell::new(Node::new(8, None, None)));
        let node5 = Rc::from(RefCell::new(Node::new(5, Some(node3), Some(node4))));

        assert!(solution(Some(node5)));
    }

    #[test]
    fn test_negative() {
        let node1 = Rc::from(RefCell::new(Node::new(1, None, None)));
        let node2 = Rc::from(RefCell::new(Node::new(5, None, None)));
        let node3 = Rc::from(RefCell::new(Node::new(3, Some(node1), Some(node2))));
        let node4 = Rc::from(RefCell::new(Node::new(8, None, None)));
        let node5 = Rc::from(RefCell::new(Node::new(5, Some(node3), Some(node4))));

        assert!(!solution(Some(node5)));
    }
}
