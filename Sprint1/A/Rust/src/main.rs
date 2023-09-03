// https://contest.yandex.ru/contest/22449/problems/

use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let nums: Vec<i32> = input
        .split_whitespace()
        .filter_map(|s| s.parse().ok())
        .collect();

    let a = nums[0];
    let x = nums[1];
    let b = nums[2];
    let c = nums[3];

    println!("{}", a * x * x + b * x + c);
}
