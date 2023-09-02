// https://contest.yandex.ru/contest/24809/problems/E/

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

pub fn solution(root: NodePtr<i32>) -> i32 {
    if let Some(root) = root {
        return std::cmp::max(
            solution(root.borrow().left.clone()),
            solution(root.borrow().right.clone()),
        ) + 1;
    }

    0
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

        assert_eq!(solution(Some(node5)), 3);
    }
}
