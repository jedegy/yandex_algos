// https://contest.yandex.ru/contest/23991/problems/A/
use std::io::BufRead;

fn poly_hash(a: usize, m: usize, s: String) -> u64 {
    let mut h = 0u64;
    let mut power = 1u64;

    for ch in s.chars().rev() {
        h = (h + ch as u64 * power) % m as u64;
        power = (power * a as u64) % m as u64;
    }

    h
}
fn main() {
    let stdin = std::io::stdin();
    let mut lines = stdin.lock().lines();

    let a: usize = lines.next().unwrap().unwrap().parse().unwrap();
    let m: usize = lines.next().unwrap().unwrap().parse().unwrap();

    let s = lines.next().unwrap().unwrap();

    println!("{}", poly_hash(a, m, s));
}
