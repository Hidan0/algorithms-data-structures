pub fn binary_search(a: &[i32], x: i32) -> i32 {
    rec_search(a, 0, (*a).len() as i32, x)
}

fn rec_search(a: &[i32], sx: i32, dx: i32, x: i32) -> i32 {
    if dx <= sx {
        return -1;
    }

    let m = (sx + dx) / 2;
    if x == (*a)[m as usize] {
        return m;
    } else if x < (*a)[m as usize] {
        return rec_search(a, sx, m, x);
    }
    rec_search(a, m + 1, dx, x)
}
