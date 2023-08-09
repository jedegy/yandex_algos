// https://contest.yandex.ru/contest/22779/problems/A/

fn transposition(matrix: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let rows = matrix.len();
    let cols = matrix[0].len();
    let mut transposed = vec![vec![0; rows]; cols];

    for i in 0..rows {
        for j in 0..cols {
            transposed[j][i] = matrix[i][j];
        }
    }

    transposed
}

fn main() {
    use std::io;

    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n = input.trim().parse::<usize>().unwrap();
    input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let m = input.trim().parse::<usize>().unwrap();

    if n == 0 || m == 0 {
        return;
    }

    let mut matrix = vec![vec![0; m]; n];
    for i in 0..n {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let row = input.trim().split_whitespace()
            .map(|s| s.parse::<i32>().unwrap())
            .collect::<Vec<_>>();

        for j in 0..m {
            matrix[i][j] = row[j];
        }
    }

    let transposed = transposition(&matrix);
    for row in &transposed {
        for &elem in row {
            print!("{} ", elem);
        }
        println!();
    }
}