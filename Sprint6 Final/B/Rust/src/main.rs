/*
-- WORKING PRINCIPLE --
This program determines whether the presented railway map is optimal. The railway map is represented as a graph where
 cities are vertices and roads are edges. A railway map is considered optimal if for any pair of cities A and B, it is
 possible to travel from city A to city B using only roads of one type, or if a route cannot be constructed at all.

The program uses the Depth First Search (DFS) algorithm to traverse the graph and check that there are no two different
 paths of different types (colors) between pairs of vertices.

-- PROOF OF CORRECTNESS --
1. To determine the visited vertices, we will use the following colors:
- WHITE - vertex has not been visited yet
- GRAY - vertex has been visited, but not all its edges have been processed
- BLACK - vertex has been visited and all its edges have been processed

2. If during the traversal of the graph we encounter a vertex of color GRAY, it means that there is a cycle in the
 graph (the vertex was visited earlier in the current traversal, indicating a cycle).
If there is a cycle in the graph, it indicates that there are multiple paths of different types (R and B) between some
 cities, making the map non-optimal.

3. Let's prove the following statement:
The minimum cycle size in the graph from the problem statement is 3.

We will prove by induction. Suppose there is a cycle A1 -> A2 -> ... -> Am -> A1.

Base of induction: m == 3, for m < 3 we cannot obtain a cycle based on the problem statement (construction).
A1 -> A2 -> A3 -> A1. It's evident that city A3 can be reached in two ways:
   - From city A1 through city A2 by roads of type R.
   - From city A1 directly by a road of type B.
And such a graph is non-optimal based on the problem statement.

Induction step: m == k. Consider the edge connecting vertices A1 and A3.
   - If A3 -> A1, then this case is already proven in the base of induction.
   - If A1 -> A3, then we get a cycle A1 -> A3 -> ... -> Am -> A1, which is 1 less in length.
   Repeating the process further, we come to a cycle of length 3.

-- TIME COMPLEXITY --
The time complexity of the DFS traversal is O(V + E), where V is the number of vertices (cities) and E is the number of edges (roads).

-- SPACE COMPLEXITY --
The space complexity of this program is O(V + E) due to the need to store the graph and the array of visited vertices.

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
