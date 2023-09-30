// https://contest.yandex.ru/contest/25069/problems/H/

use std::collections::VecDeque;
use std::io::{self, BufRead};

fn dfs(
    v: usize,
    graph: &Vec<VecDeque<usize>>,
    visited: &mut Vec<bool>,
    time_in: &mut Vec<i32>,
    time_out: &mut Vec<i32>,
    timer: &mut i32,
) {
    visited[v] = true;
    *timer += 1;
    time_in[v] = *timer;

    for &u in &graph[v] {
        if !visited[u] {
            dfs(u, graph, visited, time_in, time_out, timer);
        }
    }

    *timer += 1;
    time_out[v] = *timer;
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

    let mut graph = vec![VecDeque::new(); n];
    let mut visited = vec![false; n];
    let mut time_in = vec![-1; n];
    let mut time_out = vec![-1; n];
    let mut timer = 0;

    for _ in 0..m {
        let edge: Vec<usize> = lines
            .next()
            .unwrap()
            .unwrap()
            .split_whitespace()
            .map(|x| x.parse::<usize>().unwrap() - 1)
            .collect();

        let (from, to) = (edge[0], edge[1]);

        graph[from].push_back(to);
    }

    for neighbors in &mut graph {
        neighbors.make_contiguous().sort();
    }

    dfs(
        0,
        &graph,
        &mut visited,
        &mut time_in,
        &mut time_out,
        &mut timer,
    );

    for i in 0..n {
        println!("{} {}", time_in[i] - 1, time_out[i] - 1);
    }
}
