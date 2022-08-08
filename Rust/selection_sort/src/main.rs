fn main() {
    let mut a = [9, 0, 2, 52, 34, 11, 9, 8, 55];
    println!("Unordered: {:?}", a);
    selection_sort(&mut a);
    println!("Ordered: {:?}", a);
}

fn selection_sort(a: &mut [i32]) {
    for k in 0..=a.len() - 2 {
        let mut m = k;
        for j in k + 1..=a.len() - 1 {
            if (*a)[j] < (*a)[m] {
                m = j;
            }
        }
        let tmp = (*a)[k];
        (*a)[k] = (*a)[m];
        (*a)[m] = tmp;
    }
}
