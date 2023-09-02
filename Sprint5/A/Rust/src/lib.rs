// https://contest.yandex.ru/contest/24809/problems/A/

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

pub fn solution(root: NodePtr<i32>) -> i32 {
    match root {
        None => 0,
        Some(node) => {
            let node_ref = node.borrow();
            let mut max = node_ref.value;

            max = std::cmp::max(max, solution(node_ref.left.clone()));
            max = std::cmp::max(max, solution(node_ref.right.clone()));

            max
        }
    }
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
        let node4 = Rc::from(RefCell::new(Node::new(2, Some(node3), None)));

        assert_eq!(solution(Some(node4)), 3);
    }
}
