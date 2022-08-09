fn main() {
    let mut a = [9, 0, 2, 52, 34, 11, 9, 8, 55];
    println!("Unordered: {:?}", a);
    bubble_sort(&mut a);
    println!("Ordered: {:?}", a);
}

fn swap(a: &mut [i32], from: usize, to: usize) {
    let tmp = a[from];
    a[from] = a[to];
    a[to] = tmp;
}

fn bubble_sort(a: &mut [i32]) {
    let mut i = 1;
    let mut has_changed;

    loop {
        has_changed = false;
        for j in 1..=a.len() - i {
            if a[j] < a[j - 1] {
                swap(a, j, j - 1);
                has_changed = true;
            }
        }
        i += 1;

        if !has_changed && i > a.len() {
            break;
        }
    }
}
