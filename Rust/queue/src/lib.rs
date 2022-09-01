pub mod queue {
    pub struct Queue<T: Clone> {
        data: Vec<T>,
    }

    impl<T: Clone> Queue<T> {
        pub fn new() -> Self {
            Self { data: vec![] }
        }

        pub fn is_empty(&self) -> bool {
            self.data.len() == 0
        }

        pub fn enqueue(&mut self, k: T) {
            self.data.push(k);
        }

        pub fn dequeue(&mut self) -> Option<T> {
            if self.data.len() == 0 {
                return None;
            }

            Some(self.data.remove(0))
        }

        pub fn first(&self) -> Option<&T> {
            self.data.first()
        }
    }
}
