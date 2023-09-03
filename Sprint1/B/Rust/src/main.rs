// https://contest.yandex.ru/contest/22449/problems/B/

use std::io;

fn has_same_parity(num1: i32, num2: i32, num3: i32) -> bool {
    let parity = num1 % 2;
    num2 % 2 == parity && num3 % 2 == parity
}

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let numbers: Vec<i32> = input
        .split_whitespace()
        .filter_map(|n| n.parse().ok())
        .collect();

    let [num1, num2, num3] = [numbers[0], numbers[1], numbers[2]];

    println!(
        "{}",
        if has_same_parity(num1, num2, num3) {
            "WIN"
        } else {
            "FAIL"
        }
    );
}
