// https://contest.yandex.ru/contest/24809/problems/C/

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

fn is_anagram(tree1: NodePtr<i32>, tree2: NodePtr<i32>) -> bool {
    if tree1.is_none() && tree2.is_none() {
        return true;
    }

    if tree1.is_none() || tree2.is_none() {
        return false;
    }

    let tree1_ref = tree1.unwrap();
    let tree2_ref = tree2.unwrap();

    return tree1_ref.borrow().value == tree2_ref.borrow().value
        && is_anagram(
            tree1_ref.borrow().right.clone(),
            tree2_ref.borrow().left.clone(),
        )
        && is_anagram(
            tree1_ref.borrow().left.clone(),
            tree2_ref.borrow().right.clone(),
        );
}

pub fn solution(root: NodePtr<i32>) -> bool {
    is_anagram(root.clone(), root)
}

#[cfg(test)]
mod tests {
    use super::{solution, Node};
    use std::cell::RefCell;
    use std::rc::Rc;
    #[test]
    fn test() {
        let node1 = Rc::from(RefCell::new(Node::new(3, None, None)));
        let node2 = Rc::from(RefCell::new(Node::new(4, None, None)));
        let node3 = Rc::from(RefCell::new(Node::new(4, None, None)));
        let node4 = Rc::from(RefCell::new(Node::new(3, None, None)));
        let node5 = Rc::from(RefCell::new(Node::new(2, Some(node1), Some(node2))));
        let node6 = Rc::from(RefCell::new(Node::new(2, Some(node3), Some(node4))));
        let node7 = Rc::from(RefCell::new(Node::new(1, Some(node5), Some(node6))));

        assert!(solution(Some(node7)));
    }
}
