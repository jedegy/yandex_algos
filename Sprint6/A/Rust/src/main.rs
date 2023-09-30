// https://contest.yandex.ru/contest/25069/problems/A/

use std::collections::HashMap;
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

    let mut matrix: HashMap<usize, Vec<usize>> = HashMap::new();

    for _ in 0..m {
        let edge: Vec<usize> = lines
            .next()
            .unwrap()
            .unwrap()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        let (u, v) = (edge[0], edge[1]);
        matrix.entry(u).or_insert(Vec::new()).push(v);
    }

    for i in 1..=n {
        let vec = matrix.entry(i).or_insert(Vec::new());
        vec.sort();
    }

    for i in 1..=n {
        let vec = matrix.get(&i).unwrap();
        print!("{} ", vec.len());
        for v in vec {
            print!("{} ", v);
        }
        println!();
    }

    Ok(())
}
