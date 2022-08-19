fn main() {
    let mut a = [9, 0, 2, 52, 34, 11, 9, 8, 55, 1];
    println!("Unordered: {:?}", a);
    quick_sort(&mut a);
    println!("Ordered: {:?}", a);
}

fn quick_sort(a: &mut [i32]) {
    m_quick_sort(a, 0, a.len());
}

fn m_quick_sort(a: &mut [i32], mut start: usize, mut end: usize) {
    while end - start > 1 {
        let m = partition(a, start, end);
        if m - start < end - m {
            m_quick_sort(a, start, m);
            start = m + 1;
        } else {
            m_quick_sort(a, m + 1, end);
            end = m;
        }
    }
}

fn partition(a: &mut [i32], start: usize, end: usize) -> usize {
    let pivot = a[start];
    let mut sx = start;
    let mut dx = end;

    while sx < dx {
        loop {
            dx -= 1;
            if !(a[dx] > pivot) {
                break;
            }
        }

        loop {
            sx += 1;
            if !(sx < dx && a[sx] <= pivot) {
                break;
            }
        }

        if sx < dx {
            swap(a, sx, dx);
        }
    }

    swap(a, start, dx);
    return dx;
}

fn swap(a: &mut [i32], from: usize, to: usize) {
    let tmp = a[from];
    a[from] = a[to];
    a[to] = tmp;
}
