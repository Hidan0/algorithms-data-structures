use linked_list::linked_list::LinkedList;

fn main() {
    let mut list = LinkedList::<i32>::new();

    println!("{}", list);
    list.push(10);
    list.push(30);
    list.push(5);
    println!("{}", list);

    assert_eq!(3, list.len());
    assert_eq!(false, list.is_empty());

    assert_eq!(false, list.contains(20));
    assert_eq!(true, list.contains(5));

    assert_eq!(5, list.pop().unwrap());
    assert_eq!(2, list.len());
    println!("{}", list);

    list.pop();
    list.pop();
    println!("{}", list);
    assert_eq!(None, list.pop());
}
