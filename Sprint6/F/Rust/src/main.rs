// https://contest.yandex.ru/contest/25069/problems/F/

use std::collections::VecDeque;
use std::io::{self, BufRead};

fn min_dist_between_two_vertices(graph: &Vec<Vec<usize>>, start: usize, end: usize) -> i32 {
    let mut dist = vec![i32::MAX; graph.len()];
    dist[start] = 0;

    let mut q: VecDeque<usize> = VecDeque::new();
    q.push_back(start);

    while let Some(current) = q.pop_front() {
        for &neighbor in &graph[current] {
            if dist[neighbor] == i32::MAX {
                dist[neighbor] = dist[current] + 1;
                q.push_back(neighbor);
            }
        }
    }
    if dist[end] == i32::MAX {
        -1
    } else {
        dist[end]
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

    let se: Vec<usize> = lines
        .next()
        .unwrap()
        .unwrap()
        .split_whitespace()
        .map(|x| x.parse::<usize>().unwrap() - 1)
        .collect();
    let (start, end) = (se[0], se[1]);

    println!("{}", min_dist_between_two_vertices(&graph, start, end));
}
