// https://contest.yandex.ru/contest/24809/problems/D/

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

pub fn solution(root1: NodePtr<i32>, root2: NodePtr<i32>) -> bool {
    if root1.is_none() && root2.is_none() {
        return true;
    }

    if root1.is_none() || root2.is_none() {
        return false;
    }

    let root1_ref = root1.unwrap();
    let root2_ref = root2.unwrap();

    if root1_ref.borrow().value != root2_ref.borrow().value {
        return false;
    }

    if (root1_ref.borrow().left.is_none() && root2_ref.borrow().left.is_some())
        || (root1_ref.borrow().left.is_some() && root2_ref.borrow().left.is_none())
    {
        return false;
    }

    if (root1_ref.borrow().right.is_none() && root2_ref.borrow().right.is_some())
        || (root1_ref.borrow().right.is_some() && root2_ref.borrow().right.is_none())
    {
        return false;
    }

    return solution(
        root1_ref.borrow().left.clone(),
        root2_ref.borrow().left.clone(),
    ) && solution(
        root1_ref.borrow().right.clone(),
        root2_ref.borrow().right.clone(),
    );
}

#[cfg(test)]
mod tests {
    use super::{solution, Node};
    use std::cell::RefCell;
    use std::rc::Rc;

    #[test]
    fn test() {
        let node1 = Rc::from(RefCell::new(Node::new(1, None, None)));
        let node2 = Rc::from(RefCell::new(Node::new(2, None, None)));
        let node3 = Rc::from(RefCell::new(Node::new(3, Some(node1), Some(node2))));

        let node4 = Rc::from(RefCell::new(Node::new(1, None, None)));
        let node5 = Rc::from(RefCell::new(Node::new(2, None, None)));
        let node6 = Rc::from(RefCell::new(Node::new(3, Some(node4), Some(node5))));

        assert!(solution(Some(node3), Some(node6)));
    }
}
