// https://contest.yandex.ru/contest/24809/problems/J/

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

pub fn insert(root: NodePtr<i32>, key: i32) -> Rc<RefCell<Node<i32>>> {
    match root {
        None => Rc::from(RefCell::new(Node::new(key, None, None))),
        Some(node) => {
            let node = node.borrow_mut();
            if key < node.value {
                insert(node.left.clone(), key)
            } else {
                insert(node.right.clone(), key)
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::{insert, Node};
    use std::cell::RefCell;
    use std::rc::Rc;
    #[test]
    fn test() {
        let node1 = Rc::from(RefCell::new(Node::new(7, None, None)));
        let node2 = Rc::new(RefCell::new(Node::new(8, Some(node1), None)));
        let node3 = Rc::new(RefCell::new(Node::new(8, None, Some(node2))));

        let new_head = insert(Some(node3), 6);
        assert_eq!(new_head.borrow().value, 6);
    }
}
