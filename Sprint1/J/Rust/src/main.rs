// https://contest.yandex.ru/contest/22449/problems/J/

use std::io;

fn factorization(mut n: i32) {
    let mut i = 2;

    while i * i <= n {
        while n % i == 0 {
            print!("{} ", i);
            n /= i;
        }
        i += 1;
    }

    if n >= 2 {
        println!("{}", n);
    } else {
        println!();
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n = input.trim().parse().unwrap();

    factorization(n);
}
