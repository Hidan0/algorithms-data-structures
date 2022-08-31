pub mod linked_list {
    use std::fmt::Display;

    #[derive(Clone, Debug)]
    pub struct LinkedList<T: Copy> {
        len: usize,
        head: Link<T>,
    }

    #[derive(Clone, Debug)]
    struct Node<T: Copy> {
        val: T,
        next: Link<T>,
    }

    #[derive(Clone, Debug)]
    enum Link<T: Copy> {
        Nil,
        Link(Box<Node<T>>),
    }

    impl<T: Copy> LinkedList<T> {
        pub fn contains(&self, k: T) -> bool
        where
            T: Copy + PartialEq,
        {
            for itm in self.clone().into_iter() {
                if itm.eq(&k) {
                    return true;
                }
            }
            return false;
        }

        pub fn is_empty(&self) -> bool {
            self.len == 0
        }

        pub fn len(&self) -> usize {
            self.len
        }

        pub fn new() -> Self {
            Self {
                len: 0,
                head: Link::Nil,
            }
        }

        pub fn push(&mut self, k: T) {
            match &self.head {
                Link::Nil => {
                    self.head = Link::Link(Box::new(Node {
                        val: k,
                        next: Link::Nil,
                    }));
                }
                Link::Link(node) => {
                    self.head = Link::Link(Box::new(Node {
                        val: k,
                        next: Link::Link(node.clone()),
                    }))
                }
            }
            self.len += 1;
        }

        pub fn pop(&mut self) -> Option<T> {
            match &mut self.head {
                Link::Nil => None,
                Link::Link(node) => {
                    let val = node.val;
                    self.head = node.next.clone();
                    self.len -= 1;
                    Some(val)
                }
            }
        }
    }

    pub struct NodeCursor<T: Copy> {
        curr: Option<Node<T>>,
    }

    impl<T: Copy> Iterator for NodeCursor<T> {
        type Item = T;

        fn next(&mut self) -> Option<Self::Item> {
            match &mut self.curr {
                Some(curr) => {
                    let itm = curr.clone();
                    self.curr = match &curr.next {
                        Link::Nil => None,
                        Link::Link(next) => Some(next.as_ref().clone()),
                    };
                    Some(itm.val)
                }
                None => None,
            }
        }
    }

    impl<T: Copy> IntoIterator for LinkedList<T> {
        type Item = T;

        type IntoIter = NodeCursor<T>;

        fn into_iter(self) -> Self::IntoIter {
            match &self.head {
                Link::Nil => NodeCursor { curr: None },
                Link::Link(node) => NodeCursor {
                    curr: Some(node.as_ref().clone()),
                },
            }
        }
    }

    impl<T: Copy + Display> Display for LinkedList<T> {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            let mut str = "[".to_string();
            for itm in self.clone().into_iter() {
                str = format!("{} {} ->", str, itm);
            }

            write!(f, "{}]", str)
        }
    }
}
