// https://contest.yandex.ru/contest/25069/problems/L/

use std::io::{self, BufRead};

#[derive(Debug)]
struct Node {
    value: usize,
    to: Vec<usize>,
}

type NodeList = Vec<Node>;

fn main() -> io::Result<()> {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    let first_line = lines.next().unwrap().unwrap();
    let nm: Vec<usize> = first_line
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();
    let (n, m) = (nm[0], nm[1]);

    let mut list: NodeList = Vec::with_capacity(n);
    for i in 0..n {
        list.push(Node {
            value: i,
            to: vec![],
        });
    }

    for _ in 0..m {
        let edge: Vec<usize> = lines
            .next()
            .unwrap()
            .unwrap()
            .split_whitespace()
            .map(|num| num.parse::<usize>().unwrap() - 1)
            .collect();
        let (u, v) = (edge[0], edge[1]);

        if u != v {
            list[u].to.push(v);
            list[v].to.push(u);
        }
    }

    for node in &list {
        let mut visited = vec![false; n];
        for &to_index in &node.to {
            visited[to_index] = true;
        }

        for (i, &is_visited) in visited.iter().enumerate() {
            if i == 0 || i == node.value {
                continue;
            }
            if !is_visited {
                println!("NO");
                return Ok(());
            }
        }
    }

    println!("YES");

    Ok(())
}
