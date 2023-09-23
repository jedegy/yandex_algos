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
#include <iostream>
#include <vector>
#include <stack>

// Enum representing the state of vertices during DFS traversal
enum class Color {
    WHITE,  // Vertex not yet visited
    GRAY,   // Vertex is being processed
    BLACK   // Vertex processing is completed
};

// Perform DFS on the graph and return false if a cycle is detected
bool dfs(int v, std::vector<std::vector<int>> railways, std::vector<Color> &visited) {
    std::stack<int> stack;
    stack.push(v);

    while (!stack.empty()) {
        int current = stack.top();

        if (visited[current] == Color::WHITE) {
            visited[current] = Color::GRAY;
            for (int neighbor: railways[current]) {
                if (visited[neighbor] == Color::WHITE)
                    stack.push(neighbor);
                else if (visited[neighbor] == Color::GRAY)
                    return false;
            }
        } else {
            visited[current] = Color::BLACK;
            stack.pop();
        }
    }

    return true;
}

int main() {
    int n;
    std::cin >> n;

    // Representing the railway map as a graph
    std::vector<std::vector<int>> railways(n + 1);

    // Read input and build the graph accordingly
    for (int from = 1; from < n; ++from) {
        for (int to = from + 1; to <= n; ++to) {
            char type;
            std::cin >> type;

            // Construct directed edges according to road types
            if (type == 'R')
                railways[from].push_back(to);
            else
                railways[to].push_back(from);
        }
    }

    // Initialize the visited array
    std::vector<Color> visited(n + 1, Color::WHITE);

    // Perform DFS on each vertex
    for (int i = 1; i <= n; ++i) {
        if (visited[i] != Color::WHITE)
            continue;

        // If a cycle is detected
        if (!dfs(i, railways, visited)) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    // If no cycle is detected
    std::cout << "YES" << std::endl;

    return 0;
}
