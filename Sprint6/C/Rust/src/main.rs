// https://contest.yandex.ru/contest/25069/problems/C/

use std::io::{self, BufRead};

fn dfs(v: usize, g: &Vec<Vec<usize>>, visited: &mut Vec<bool>) {
    visited[v] = true;
    print!("{} ", v + 1);

    for &neighbor in &g[v] {
        if !visited[neighbor] {
            dfs(neighbor, g, visited);
        }
    }
}

fn main() -> io::Result<()> {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    let first_line = lines.next().unwrap().unwrap();
    let nm: Vec<usize> = first_line
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();
    let (n, m) = (nm[0], nm[1]);

    let mut g: Vec<Vec<usize>> = vec![vec![]; n];
    let mut visited: Vec<bool> = vec![false; n];

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

    for neighbors in &mut g {
        neighbors.sort();
    }

    let start_v: usize = lines.next().unwrap().unwrap().parse::<usize>().unwrap() - 1;

    dfs(start_v, &g, &mut visited);

    println!();
    Ok(())
}
