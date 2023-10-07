// https://contest.yandex.ru/contest/25596/problems/O/

use std::collections::VecDeque;

fn main() {
    let mut lines = std::io::stdin().lines();
    let line = lines.next().unwrap().unwrap();
    let mut n_m = line.split_whitespace();
    let n = n_m.next().unwrap().parse::<usize>().unwrap();
    let m = n_m.next().unwrap().parse::<usize>().unwrap();

    let mut graph = vec![vec![]; n];
    let mut in_degree = vec![0; n];

    for _ in 0..m {
        let line = lines.next().unwrap().unwrap();
        let mut uv = line.split_whitespace();
        let u = uv.next().unwrap().parse::<usize>().unwrap() - 1;
        let v = uv.next().unwrap().parse::<usize>().unwrap() - 1;
        graph[u].push(v);
        in_degree[v] += 1usize;
    }

    let line = lines.next().unwrap().unwrap();
    let mut ab = line.split_whitespace();
    let a = ab.next().unwrap().parse::<usize>().unwrap() - 1;
    let b = ab.next().unwrap().parse::<usize>().unwrap() - 1;

    let mut dp = vec![0usize; n];
    dp[a] = 1;

    let mut q: VecDeque<usize> = VecDeque::new();
    for (i, d) in in_degree.iter().enumerate() {
        if *d == 0 {
            q.push_back(i);
        }
    }

    while let Some(curr) = q.pop_front() {
        for &neighbor in &graph[curr] {
            dp[neighbor] = (dp[neighbor] + dp[curr]) % usize::MAX;
            in_degree[neighbor] -= 1;
            if in_degree[neighbor] == 0 {
                q.push_back(neighbor);
            }
        }
    }

    println!("{}", dp[b]);
}
