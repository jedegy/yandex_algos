// https://contest.yandex.ru/contest/25069/problems/B/

use std::io::{self, BufRead};

fn main() -> io::Result<()> {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    let first_line = lines.next().unwrap().unwrap();
    let nm: Vec<usize> = first_line
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();
    let (n, m) = (nm[0], nm[1]);

    let mut matrix = vec![vec![0; n]; n];

    for _ in 0..m {
        let edge: Vec<usize> = lines
            .next()
            .unwrap()
            .unwrap()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        let (u, v) = (edge[0], edge[1]);

        matrix[u - 1][v - 1] = 1;
    }

    for row in &matrix {
        for &val in row {
            print!("{} ", val);
        }
        println!();
    }

    Ok(())
}
