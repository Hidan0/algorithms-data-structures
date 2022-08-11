fn main() {
    let mut a = [9, 0, 2, 52, 34, 11, 9, 8, 55];
    println!("Unordered: {:?}", a);
    merge_sort(&mut a);
    println!("Ordered: {:?}", a);
}

fn merge_sort(a: &mut [i32]) {
    let mut x = vec![0; a.len()];
    r_merge_sort(a, 0, a.len(), &mut x);
}

fn r_merge_sort(a: &mut [i32], start: usize, end: usize, x: &mut [i32]) {
    if end - start > 1 {
        let m = (start + end) / 2;
        r_merge_sort(a, start, m, x);
        r_merge_sort(a, m, end, x);
        merge(a, start, m, end, x);
    }
}

fn merge(a: &mut [i32], start: usize, m: usize, end: usize, x: &mut [i32]) {
    let mut start_1 = start;
    let mut start_2 = m;
    let mut k = 0;

    while start_1 < m && start_2 < end {
        if a[start_1] <= a[start_2] {
            x[k] = a[start_1];
            start_1 += 1;
        } else {
            x[k] = a[start_2];
            start_2 += 1;
        }
        k += 1;
    }

    if start_1 < m {
        for j in start_1..m {
            x[k] = a[j];
            k += 1;
        }
    } else {
        for j in start_2..end {
            x[k] = a[j];
            k += 1;
        }
    }

    for k in 0..end - start {
        a[start + k] = x[k];
    }
}
