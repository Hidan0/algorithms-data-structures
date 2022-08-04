mod iterative;
mod recursive;

fn main() {
    let a = [0, 1, 3, 6, 10, 12, 30, 32, 50];
    assert_eq!(4, recursive::binary_search(&a, 10));
    assert_eq!(1, recursive::binary_search(&a, 1));
    assert_eq!(7, recursive::binary_search(&a, 32));
    assert_eq!(-1, recursive::binary_search(&a, 2));

    assert_eq!(4, iterative::binary_search(&a, 10));
    assert_eq!(1, iterative::binary_search(&a, 1));
    assert_eq!(7, iterative::binary_search(&a, 32));
    assert_eq!(-1, iterative::binary_search(&a, 2));
}
