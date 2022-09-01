use lib::queue::Queue;

mod lib;

fn main() {
    let mut q = Queue::new();
    assert_eq!(true, q.is_empty());
    assert_eq!(None, q.first());

    q.enqueue("Hello");
    q.enqueue("World");
    assert_eq!(false, q.is_empty());
    assert_eq!(&"Hello", q.first().unwrap());

    assert_eq!(q.dequeue().unwrap(), "Hello");
    q.enqueue("!");
    assert_eq!(q.dequeue().unwrap(), "World");
    _ = q.dequeue();
    assert_eq!(true, q.is_empty());
}
