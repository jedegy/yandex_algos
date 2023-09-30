// https://contest.yandex.ru/contest/25069/problems/M/

use std::collections::VecDeque;
use std::io::{self, BufRead};

fn is_bipartite(graph: &Vec<Vec<i32>>) -> bool {
    let mut color = vec![0; graph.len()];
    let mut q = VecDeque::new();

    for start in 0..graph.len() {
        if color[start] == 0 {
            color[start] = 1;
            q.push_back(start);

            while let Some(u) = q.pop_front() {
                for &v in &graph[u] {
                    let v = v as usize;
                    if color[v] == 0 {
                        color[v] = 3 - color[u];
                        q.push_back(v);
                    } else if color[v] == color[u] {
                        return false;
                    }
                }
            }
        }
    }

    true
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

    let mut graph = vec![vec![]; n];

    for _ in 0..m {
        let edge: Vec<usize> = lines
            .next()
            .unwrap()
            .unwrap()
            .split_whitespace()
            .map(|num| num.parse::<usize>().unwrap() - 1)
            .collect();
        let (u, v) = (edge[0], edge[1]);

        graph[u].push(v as i32);
        graph[v].push(u as i32);
    }

    println!("{}", if is_bipartite(&graph) { "YES" } else { "NO" });

    Ok(())
}
