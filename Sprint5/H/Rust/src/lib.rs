// https://contest.yandex.ru/contest/24809/problems/H/

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

fn numeric_paths(root: NodePtr<i32>, mut current_number: i32, total_sum: &mut i32) {
    if let Some(root) = root {
        current_number = current_number * 10 + root.borrow().value;

        if root.borrow().left.is_none() && root.borrow().right.is_none() {
            *total_sum += current_number;
            return;
        }

        numeric_paths(root.borrow().left.clone(), current_number, total_sum);
        numeric_paths(root.borrow().right.clone(), current_number, total_sum);
    }
}

pub fn solution(root: NodePtr<i32>) -> i32 {
    let mut total_sum = 0;
    numeric_paths(root, 0, &mut total_sum);

    total_sum
}

#[cfg(test)]
mod tests {
    use super::{solution, Node};
    use std::cell::RefCell;
    use std::rc::Rc;

    #[test]
    fn test() {
        let node1 = Rc::from(RefCell::new(Node::new(2, None, None)));
        let node2 = Rc::from(RefCell::new(Node::new(1, None, None)));
        let node3 = Rc::from(RefCell::new(Node::new(3, Some(node1), Some(node2))));
        let node4 = Rc::from(RefCell::new(Node::new(2, None, None)));
        let node5 = Rc::from(RefCell::new(Node::new(1, Some(node4), Some(node3))));

        assert_eq!(solution(Some(node5)), 275);
    }
}
