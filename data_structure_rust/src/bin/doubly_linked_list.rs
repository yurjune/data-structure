use std::cell::RefCell;
use std::rc::{Rc, Weak};

type Val = i32;

struct Node {
    val: Val,
    next: Option<Rc<RefCell<Node>>>,
    prev: Option<Weak<RefCell<Node>>>,
}

impl Node {
    fn new(val: Val) -> Self {
        Self {
            val,
            next: None,
            prev: None,
        }
    }
}

struct DoublyLinkedList {
    size: usize,
    head: Option<Rc<RefCell<Node>>>,
    tail: Option<Rc<RefCell<Node>>>,
}

impl DoublyLinkedList {
    fn new() -> Self {
        Self {
            size: 0,
            head: None,
            tail: None,
        }
    }

    fn len(&self) -> usize {
        self.size
    }

    fn is_empty(&self) -> bool {
        self.size == 0
    }

    fn front(&self) -> Option<Val> {
        self.head.as_ref().map(|s| s.borrow().val)
    }

    fn rear(&self) -> Option<Val> {
        self.tail.as_ref().map(|s| s.borrow().val)
    }

    fn insert_front(&mut self, val: Val) {
        let node = Rc::new(RefCell::new(Node::new(val)));
        match self.head.take() {
            Some(old_head) => {
                node.borrow_mut().next = Some(old_head.clone());
                old_head.borrow_mut().prev = Some(Rc::downgrade(&node));
                self.head = Some(node);
            }
            None => {
                self.head = Some(node.clone());
                self.tail = Some(node);
            }
        }
        self.size += 1;
    }

    fn insert_rear(&mut self, val: Val) {
        let node = Rc::new(RefCell::new(Node::new(val)));
        match self.tail.take() {
            Some(old_tail) => {
                node.borrow_mut().prev = Some(Rc::downgrade(&old_tail));
                old_tail.borrow_mut().next = Some(node.clone());
                self.tail = Some(node);
            }
            None => {
                self.head = Some(node.clone());
                self.tail = Some(node);
            }
        }
        self.size += 1;
    }

    fn pop_front(&mut self) -> Option<Val> {
        self.head.take().map(|old_head| {
            let val = old_head.borrow().val;
            self.head = old_head.borrow_mut().next.take();
            if let Some(ref new_head) = self.head {
                new_head.borrow_mut().prev = None;
            } else {
                self.tail = None;
            }
            self.size -= 1;
            val
        })
    }

    fn pop_rear(&mut self) -> Option<Val> {
        self.tail.take().map(|old_tail| {
            let val = old_tail.borrow().val;
            self.tail = old_tail
                .borrow_mut()
                .prev
                .as_ref()
                .and_then(|weak| weak.upgrade());
            if let Some(ref new_tail) = self.tail {
                new_tail.borrow_mut().next = None;
            } else {
                self.head = None;
            }
            self.size -= 1;
            val
        })
    }

    fn traverse(&self) {
        let mut node = self.head.clone();
        while let Some(el) = node {
            print!("{} -> ", el.borrow().val);
            node = el.borrow().next.clone();
        }
        println!();
    }

    fn traverse_reverse(&self) {
        let mut node = self.tail.clone();
        while let Some(el) = node {
            print!("{} -> ", el.borrow().val);
            node = el.borrow().prev.as_ref().and_then(|weak| weak.upgrade());
        }
        println!();
    }
}

fn main() {
    let mut dl = DoublyLinkedList::new();
    println!("Empty: {}", dl.is_empty());
    println!("Size: {}", dl.len());

    dl.insert_front(3);
    dl.insert_front(2);
    dl.insert_front(1);
    dl.insert_rear(4);
    dl.insert_rear(5);
    dl.insert_rear(6);

    if let Some(front) = dl.front() {
        println!("front: {}", front);
    }
    if let Some(rear) = dl.rear() {
        println!("rear: {}", rear);
    }

    println!("Traverse:");
    dl.traverse();
    println!("Traverse reverse:");
    dl.traverse_reverse();

    dl.pop_front();
    dl.pop_rear();
    println!("Traverse:");
    dl.traverse();
}
