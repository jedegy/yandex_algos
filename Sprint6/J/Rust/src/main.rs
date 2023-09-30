// https://contest.yandex.ru/contest/25069/problems/J/

use std::collections::VecDeque;
use std::io::{self, BufRead};

fn dfs(start_v: usize, g: &Vec<Vec<usize>>, visited: &mut Vec<bool>, result: &mut VecDeque<usize>) {
    visited[start_v] = true;
    for &u in &g[start_v] {
        if !visited[u] {
            dfs(u, g, visited, result);
        }
    }
    result.push_front(start_v);
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    let first_line = lines.next().unwrap().unwrap();
    let nm: Vec<usize> = first_line
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();
    let (n, m) = (nm[0], nm[1]);

    let mut g = vec![vec![]; n];
    let mut visited = vec![false; n];
    let mut result = VecDeque::new();

    for _ in 0..m {
        let edge: Vec<usize> = lines
            .next()
            .unwrap()
            .unwrap()
            .split_whitespace()
            .map(|x| x.parse::<usize>().unwrap() - 1)
            .collect();

        let (from, to) = (edge[0], edge[1]);
        g[from].push(to);
    }

    for i in 0..n {
        if !visited[i] {
            dfs(i, &g, &mut visited, &mut result);
        }
    }

    for &v in &result {
        print!("{} ", v + 1);
    }
    println!();
}
