// https://contest.yandex.ru/contest/25069/problems/D/

use std::collections::VecDeque;
use std::io::{self, BufRead};

fn bfs(start_v: usize, g: &[Vec<usize>]) {
    let mut visited = vec![false; g.len()];
    let mut q = VecDeque::new();

    q.push_back(start_v);
    visited[start_v] = true;

    while let Some(current_v) = q.pop_front() {
        print!("{} ", current_v + 1);

        for &neighbor in &g[current_v] {
            if !visited[neighbor] {
                q.push_back(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    println!();
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

    let mut g: Vec<Vec<usize>> = vec![vec![]; n];

    for _ in 0..m {
        let edge: Vec<usize> = lines
            .next()
            .unwrap()
            .unwrap()
            .split_whitespace()
            .map(|x| x.parse::<usize>().unwrap() - 1)
            .collect();
        let (u, v) = (edge[0], edge[1]);
        g[u].push(v);
        g[v].push(u);
    }

    for neighbors in g.iter_mut() {
        neighbors.sort();
    }

    let start_v: usize = lines.next().unwrap().unwrap().parse::<usize>().unwrap() - 1;
    bfs(start_v, &g);
}
