/*
-- WORKING PRINCIPLE --
This program determines whether the given railway map is optimal. A railway map is represented as a graph, where cities
 are vertices and roads are edges. A railway map is considered optimal if, for any pair of cities A and B, it is
 possible to go from city A to city B only using roads of one type or if the route cannot be built at all.

The program uses the Depth First Search (DFS) algorithm to traverse the graph and detect whether there are any cycles,
 indicating that the map is not optimal. A cycle is detected when there is a back edge present in the graph.

-- PROOF OF CORRECTNESS --
The program correctly identifies whether the given railway map is optimal or not by performing the following steps:
1. Represent the railway map as a directed graph.
2. Traverse the graph using DFS and mark vertices with three colors to indicate their state.
3. Detect any back edges during the DFS traversal to identify cycles in the graph.

If no cycles are detected during the traversal, the railway map is considered optimal; otherwise, it is not optimal.

-- TIME COMPLEXITY --
The time complexity of the DFS traversal is O(V + E), where V is the number of vertices (cities), and E is the number of edges (roads).

-- SPACE COMPLEXITY --
The space complexity of this program is O(V + E) due to the storage required for the graph representation and the visited array.

Link to successful report: https://contest.yandex.ru/contest/25070/run-report/91164697/
*/

use std::collections::VecDeque;
use std::io::{self, BufRead};

// Enum representing the state of vertices during DFS traversal
#[derive(PartialEq, Eq, Clone, Copy)]
enum Color {
    White, // Vertex not yet visited
    Gray,  // Vertex is being processed
    Black, // Vertex processing is completed
}

// Perform DFS on the graph and return false if a cycle is detected
fn dfs(v: usize, railways: &Vec<Vec<usize>>, visited: &mut Vec<Color>) -> bool {
    let mut stack = VecDeque::new();
    stack.push_front(v);

    while !stack.is_empty() {
        let current = stack.front().unwrap();

        if visited[*current] == Color::White {
            visited[*current] = Color::Gray;
            for &neighbor in &railways[*current] {
                if visited[neighbor] == Color::White {
                    stack.push_front(neighbor);
                } else if visited[neighbor] == Color::Gray {
                    return false;
                }
            }
        } else {
            let current = stack.pop_front().unwrap();
            visited[current] = Color::Black;
        }
    }

    true
}

fn main() {
    let mut lines = io::stdin().lock().lines();

    let n: usize = lines.next().unwrap().unwrap().parse().unwrap();
    let mut railways = vec![vec![]; n + 1];

    // Read input and build the graph accordingly
    for from in 1..n {
        let line = lines.next().unwrap().unwrap();
        for (to, type_) in (from + 1..=n).zip(line.chars()) {
            if type_ == 'R' {
                railways[from].push(to);
            } else {
                railways[to].push(from);
            }
        }
    }

    // Initialize the visited array
    let mut visited = vec![Color::White; n + 1];

    // Perform DFS on each vertex
    for i in 1..=n {
        if visited[i] != Color::White {
            continue;
        }

        // If a cycle is detected
        if !dfs(i, &railways, &mut visited) {
            println!("NO");
            return;
        }
    }

    // If no cycle is detected
    println!("YES");
}
