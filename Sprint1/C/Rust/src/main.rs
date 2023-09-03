// https://contest.yandex.ru/contest/22449/problems/C/

use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    let n: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();
    let m: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();

    let mut matrix = vec![vec![0; m]; n];

    for matrix_row in matrix.iter_mut() {
        let row: Vec<i32> = lines
            .next()
            .unwrap()
            .unwrap()
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();
        *matrix_row = row;
    }

    let row: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();
    let col: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();

    let mut neighbors = vec![];

    if col > 0 {
        neighbors.push(matrix[row][col - 1]);
    }
    if col + 1 < m {
        neighbors.push(matrix[row][col + 1]);
    }
    if row > 0 {
        neighbors.push(matrix[row - 1][col]);
    }
    if row + 1 < n {
        neighbors.push(matrix[row + 1][col]);
    }

    neighbors.sort();
    let output = neighbors
        .iter()
        .map(|&x| x.to_string())
        .collect::<Vec<String>>()
        .join(" ");

    println!("{}", output);
}
