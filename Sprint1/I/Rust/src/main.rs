// https://contest.yandex.ru/contest/22449/problems/I/

use std::io;

fn is_four_degree(n: i32) -> bool {
    match n {
        1 => true,
        _ if n % 4 != 0 => false,
        _ => is_four_degree(n >> 2),
    }
}

fn main() -> io::Result<()> {
    let mut input = String::new();
    io::stdin().read_line(&mut input)?;

    let n = input.trim().parse::<i32>().unwrap();
    if is_four_degree(n) {
        println!("True");
    } else {
        println!("False");
    }

    Ok(())
}
