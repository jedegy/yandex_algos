// https://contest.yandex.ru/contest/25069/problems/E/

use std::io::{self, BufRead};

fn dfs(v: usize, g: &Vec<Vec<usize>>, visited: &mut Vec<bool>, component: &mut Vec<usize>) {
    visited[v] = true;
    component.push(v);
    for &u in &g[v] {
        if !visited[u] {
            dfs(u, g, visited, component);
        }
    }
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

    let mut visited: Vec<bool> = vec![false; n];
    let mut components: Vec<Vec<usize>> = Vec::new();

    for i in 0..n {
        if !visited[i] {
            let mut component: Vec<usize> = Vec::new();
            dfs(i, &g, &mut visited, &mut component);
            component.sort();
            components.push(component);
        }
    }

    println!("{}", components.len());
    for component in &components {
        for &v in component {
            print!("{} ", v + 1);
        }
        println!();
    }
}
