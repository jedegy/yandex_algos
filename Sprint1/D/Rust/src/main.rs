// https://contest.yandex.ru/contest/22449/problems/D/

use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();

    if n == 1 {
        println!("1");
        return;
    }

    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let temperatures: Vec<i32> = input
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();

    let mut chaotic = 0;

    if temperatures[0] > temperatures[1] {
        chaotic += 1;
    }

    for i in 2..n {
        if temperatures[i - 1] > temperatures[i] && temperatures[i - 1] > temperatures[i - 2] {
            chaotic += 1;
        }
    }

    if temperatures[n - 1] > temperatures[n - 2] {
        chaotic += 1;
    }

    println!("{}", chaotic);
}
