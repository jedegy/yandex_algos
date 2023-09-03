// https://contest.yandex.ru/contest/22449/problems/G/

use std::io;

fn dec_to_bin(mut n: i32) -> String {
    if n == 0 {
        return "0".to_string();
    }

    let mut result = String::new();
    while n > 0 {
        result.push_str(&(n % 2).to_string());
        n >>= 1;
    }

    result.chars().rev().collect()
}

fn main() -> io::Result<()> {
    let mut input = String::new();
    io::stdin().read_line(&mut input)?;
    let n: i32 = input.trim().parse().unwrap();

    println!("{}", dec_to_bin(n));
    Ok(())
}
