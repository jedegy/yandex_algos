// https://contest.yandex.ru/contest/25069/problems/K/

use std::collections::BinaryHeap;
use std::collections::HashSet;
use std::io::{self, BufRead};

#[derive(Eq, PartialEq)]
struct State {
    cost: i32,
    vertex: usize,
}

impl Ord for State {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        other.cost.cmp(&self.cost)
    }
}

impl PartialOrd for State {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

fn dijkstra(vertex_s: usize, graph: &[Vec<(usize, i32)>], dist: &mut [i32]) {
    let mut visited = HashSet::new();
    let mut heap = BinaryHeap::new();

    heap.push(State {
        cost: 0,
        vertex: vertex_s,
    });
    dist[vertex_s] = 0;

    while let Some(State { cost, vertex }) = heap.pop() {
        if visited.contains(&vertex) {
            continue;
        }

        visited.insert(vertex);

        for &(next_vertex, weight) in &graph[vertex] {
            let next_cost = cost + weight;

            if next_cost < dist[next_vertex] {
                heap.push(State {
                    cost: next_cost,
                    vertex: next_vertex,
                });
                dist[next_vertex] = next_cost;
            }
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

    let mut graph: Vec<Vec<(usize, i32)>> = vec![vec![]; n];

    for _ in 0..m {
        let edge: Vec<i32> = lines
            .next()
            .unwrap()
            .unwrap()
            .split_whitespace()
            .map(|x| x.parse::<i32>().unwrap())
            .collect();
        let (u, v, l) = (edge[0] as usize, edge[1] as usize, edge[2]);
        graph[u - 1].push((v - 1, l));
        graph[v - 1].push((u - 1, l));
    }

    for i in 0..n {
        let mut dist = vec![i32::MAX; n];
        dijkstra(i, &graph, &mut dist);

        for d in &dist {
            if *d == i32::MAX {
                print!("-1 ");
            } else {
                print!("{} ", d);
            }
        }
        println!();
    }
}
