fn main() {
    let mut a = [9, 0, 2, 52, 34, 11, 9, 8, 55];
    println!("Unordered: {:?}", a);
    insertion_sort(&mut a);
    println!("Ordered: {:?}", a);
}

fn insertion_sort(a: &mut [i32]) {
    for k in 1..a.len() as i32 {
        let x = a[k as usize];
        let mut j: i32 = k - 1;
        while j >= 0 && a[j as usize] > x {
            a[(j + 1) as usize] = a[j as usize];
            j -= 1;
        }
        a[(j + 1) as usize] = x;
    }
}
