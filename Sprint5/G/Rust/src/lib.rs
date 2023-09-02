// https://contest.yandex.ru/contest/24809/problems/G/

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

fn find_max_path(root: NodePtr<i32>, max_path: &mut i32) -> i32 {
    if let Some(root) = root {
        let left_max = std::cmp::max(0, find_max_path(root.borrow().left.clone(), max_path));
        let right_max = std::cmp::max(0, find_max_path(root.borrow().right.clone(), max_path));

        *max_path = std::cmp::max(*max_path, root.borrow().value + left_max + right_max);
        *max_path = std::cmp::max(
            *max_path,
            root.borrow().value + std::cmp::max(left_max, right_max),
        );

        return root.borrow().value + std::cmp::max(left_max, right_max);
    }

    0
}

pub fn solution(root: NodePtr<i32>) -> i32 {
    let mut max_path = i32::MIN;
    let _ = find_max_path(root, &mut max_path);
    max_path
}

#[cfg(test)]
mod tests {
    use super::{solution, Node};
    use std::cell::RefCell;
    use std::rc::Rc;

    #[test]
    fn test() {
        let node1 = Rc::from(RefCell::new(Node::new(5, None, None)));
        let node2 = Rc::from(RefCell::new(Node::new(1, None, None)));
        let node3 = Rc::from(RefCell::new(Node::new(-3, Some(node2), Some(node1))));
        let node4 = Rc::from(RefCell::new(Node::new(2, None, None)));
        let node5 = Rc::from(RefCell::new(Node::new(2, Some(node4), Some(node3))));

        assert_eq!(solution(Some(node5)), 6);
    }
}
