// https://contest.yandex.ru/contest/26131/problems/G/
use std::io::BufRead;

fn check_equal(s: &[i32], start: usize, pattern: &Vec<i32>, shift: i32) -> bool {
    for i in 0..pattern.len() {
        if s[start + i] != pattern[i] + shift {
            return false;
        }
    }
    true
}

fn main() {
    let mut lines = std::io::stdin().lock().lines();
    let n: usize = lines.next().unwrap().unwrap().parse().unwrap();
    let mut measure_res = Vec::with_capacity(n);

    measure_res.extend(
        lines
            .next()
            .unwrap()
            .unwrap()
            .split_whitespace()
            .map(|s| s.parse::<i32>().unwrap()),
    );

    let m: usize = lines.next().unwrap().unwrap().parse().unwrap();
    let mut sample = Vec::with_capacity(m);

    sample.extend(
        lines
            .next()
            .unwrap()
            .unwrap()
            .split_whitespace()
            .map(|s| s.parse::<i32>().unwrap()),
    );

    for i in 0..=n - m {
        let shift = measure_res[i] - sample[0];
        if check_equal(&measure_res, i, &sample, shift) {
            print!("{} ", i + 1);
        }
    }
}
