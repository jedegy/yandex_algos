/*
-- WORKING PRINCIPLE --
This program finds the weight of the Maximum Spanning Tree (MST) in a given undirected graph representing the office's scheme.
It uses the Prim’s algorithm by considering the largest weight edge at every step. It utilizes a priority_queue to always
pick the maximum weight edge from the available options.

-- PROOF OF CORRECTNESS --
The program correctly computes the weight of the Maximum Spanning Tree using the following steps:
1. Represents the graph as an adjacency list.
2. Implements a modified Prim’s algorithm, starting from an arbitrary vertex, which at every step chooses the maximum weight edge.
3. Uses a priority_queue to efficiently select the maximum weight edge.
4. Uses a vector "visited" to keep track of visited vertices to avoid cycles.
5. Continues the process until all vertices are included in the MST or it is evident that the graph is not connected.

If any vertex is not included in the MST, the program concludes that the graph is not connected, thus a spanning tree is not possible.

-- TIME COMPLEXITY --
The time complexity of the modified Prim’s algorithm is O(E log E + V), where V is the number of vertices, and E is the number of edges.

-- SPACE COMPLEXITY --
The space complexity of the program is O(V + E) due to the storage required for the graph representation, visited array, and priority_queue.

Link to successful report: https://contest.yandex.ru/contest/25070/run-report/91167565/
*/

use std::collections::{BinaryHeap, HashSet};
use std::io::{self, BufRead};

/// `Edge` struct represents an edge in a graph.
#[derive(Clone, Eq, PartialEq)]
struct Edge {
    weight: usize,
    node: usize,
}

impl Ord for Edge {
    /// Compare `self` with `other` based on their `weight`.
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        self.weight.cmp(&other.weight)
    }
}

impl PartialOrd for Edge {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

// Function to find the weight of the Minimum Spanning Tree (MST) of a graph.
///
/// # Parameters
/// - `graph`: A reference to a vector representing an adjacency list of the graph.
///
/// # Returns
///
/// Returns `Some(usize)` if MST exists, else returns `None`.
fn find_weight_mst(graph: &[Vec<Edge>]) -> Option<usize> {
    let mut result = 0;
    let mut queue = BinaryHeap::new();
    let mut visited = HashSet::new();

    visited.insert(1);
    queue.extend(graph[1].iter().cloned());

    while let Some(edge) = queue.pop() {
        if !visited.insert(edge.node) {
            continue;
        }

        result += edge.weight;
        queue.extend(
            graph[edge.node]
                .iter()
                .cloned()
                .filter(|e| !visited.contains(&e.node)),
        );
    }

    if visited.len() == graph.len() - 1 {
        Some(result)
    } else {
        None
    }
}

fn main() -> io::Result<()> {
    let mut lines = io::stdin().lock().lines();

    let (n, m) = {
        let first_line = lines.next().unwrap().unwrap();
        let nm: Vec<usize> = first_line
            .trim()
            .split_whitespace()
            .map(|s| s.parse::<usize>().unwrap())
            .collect();
        (nm[0], nm[1])
    };

    if n > 1 && m == 0 {
        println!("Oops! I did it again");
        return Ok(());
    }

    let mut graph: Vec<Vec<Edge>> = vec![vec![]; n + 1];

    for _ in 0..n {
        let line = lines.next().unwrap().unwrap();

        let vuw: Vec<usize> = line
            .trim()
            .split_whitespace()
            .map(|s| s.parse::<usize>().unwrap())
            .collect();
        let (v, u, w) = (vuw[0], vuw[1], vuw[2]);

        if v == u {
            continue;
        }

        graph[v].push(Edge { weight: w, node: u });
        graph[u].push(Edge { weight: w, node: v });
    }

    match find_weight_mst(&graph) {
        Some(weight) => println!("{}", weight),
        None => println!("Oops! I did it again"),
    }

    Ok(())
}
