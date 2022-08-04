pub fn binary_search(a: &[i32], x: i32) -> i32 {
    let mut sx = 0;
    let mut dx = (*a).len() as i32;
    let mut pos = -1;

    while sx < dx && pos == -1 {
        let m = (sx + dx) / 2;

        if x == (*a)[m as usize] {
            pos = m;
        } else if x < (*a)[m as usize] {
            dx = m;
        } else {
            sx = m + 1;
        }
    }

    pos
}
