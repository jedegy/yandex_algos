// https://contest.yandex.ru/contest/24809/problems/K/

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

fn print_range(root: NodePtr<i32>, l: i32, r: i32) {
    if let Some(root) = root {
        if root.borrow().value < l {
            print_range(root.borrow().right.clone(), l, r);
        } else if root.borrow().value > r {
            print_range(root.borrow().left.clone(), l, r);
        } else {
            print_range(root.borrow().left.clone(), l, root.borrow().value);
            print!("{} ", root.borrow().value);
            print_range(root.borrow().right.clone(), root.borrow().value, r);
        }
    }
}

#[cfg(test)]
mod tests {
    use super::{print_range, Node};
    use std::cell::RefCell;
    use std::rc::Rc;

    #[test]
    fn test() {
        let node1 = Rc::from(RefCell::new(Node::new(2, None, None)));
        let node2 = Rc::from(RefCell::new(Node::new(4, None, Some(node1))));
        let node3 = Rc::from(RefCell::new(Node::new(8, None, None)));
        let node4 = Rc::from(RefCell::new(Node::new(8, None, Some(node3))));
        let node5 = Rc::from(RefCell::new(Node::new(9, Some(node4), None)));
        let node6 = Rc::from(RefCell::new(Node::new(10, Some(node5), None)));
        let node7 = Rc::from(RefCell::new(Node::new(5, Some(node2), Some(node6))));

        print_range(Some(node7), 2, 8);
    }
}
