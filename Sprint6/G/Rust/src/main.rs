// https://contest.yandex.ru/contest/25069/problems/G/

use std::collections::VecDeque;
use std::io::{self, BufRead};

fn bfs(start: usize, g: &Vec<Vec<usize>>) -> usize {
    let n = g.len();
    let mut distance = vec![-1; n];
    let mut q = VecDeque::new();

    q.push_back(start);
    distance[start] = 0;
    let mut max_val = 0;

    while let Some(current_v) = q.pop_front() {
        for &neighbor in &g[current_v] {
            if distance[neighbor] == -1 {
                q.push_back(neighbor);
                distance[neighbor] = distance[current_v] + 1;
                max_val = std::cmp::max(max_val, distance[neighbor] as usize);
            }
        }
    }

    max_val
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

    let mut graph = vec![vec![]; n];

    for _ in 0..m {
        let edge: Vec<usize> = lines
            .next()
            .unwrap()
            .unwrap()
            .split_whitespace()
            .map(|x| x.parse::<usize>().unwrap() - 1)
            .collect();

        let (u, v) = (edge[0], edge[1]);
        graph[u].push(v);
        graph[v].push(u);
    }

    let s: usize = lines.next().unwrap().unwrap().parse::<usize>().unwrap() - 1;

    println!("{}", bfs(s, &graph));
}
