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

#include <iostream>
#include <vector>
#include <queue>
#include <optional>

struct Edge {
    int weight;
    int node;
};

// Overloading the '<' operator to make priority_queue a max heap based on edge weight.
bool operator<(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Function to find weight of the Maximum Spanning Tree using a modified Prim’s algorithm.
std::optional<int> find_weight_MST(const std::vector<std::vector<Edge>>& graph) {
    int result = 0;
    std::priority_queue<Edge> queue;  // Max heap to always select the edge with maximum weight.
    std::vector<bool> visited(graph.size(), false);  // To keep track of visited nodes.

    // Start from the vertex labeled '1'.
    visited[1] = true;
    // Push all the adjacent edges of the starting vertex to the priority_queue.
    for (const auto& edge : graph[1]) {
        queue.push(edge);
    }

    // Continue until there are no more edges in the priority_queue.
    while (!queue.empty()) {
        auto edge = queue.top();
        queue.pop();

        // Skip the edges leading to the already visited vertices to avoid cycles.
        if (visited[edge.node])
            continue;
        result += edge.weight;  // Add the weight of the chosen edge to the result.
        visited[edge.node] = true;  // Mark the connected vertex as visited.

        // Add all the adjacent edges of the newly added vertex to the priority_queue.
        for (const auto& e : graph[edge.node]) {
            if (!visited[e.node]) {
                queue.push(e);
            }
        }
    }

    // Check if all vertices are included in the MST.
    if (!std::all_of(visited.begin() + 1, visited.end(), [](bool v){ return v; })) {
        return std::nullopt;
    }

    // Return the weight of the Maximum Spanning Tree.
    return result;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    // If there are multiple vertices but no edges, the graph is not connected.
    if (n > 1 && m == 0) {
        std::cout << "Oops! I did it again" << std::endl;
        return 0;
    }

    std::vector<std::vector<Edge>> graph(n + 1);

    // Read the graph from the input.
    for (int i = 0; i < m; i++) {
        int v, u, w;
        std::cin >> v >> u >> w;
        if (v == u)
            continue;  // Skip the loops.

        // Add the edge to the graph in both directions as the graph is undirected.
        graph[v].push_back(Edge{w, u});
        graph[u].push_back(Edge{w, v});
    }

    // Find the Maximum Spanning Tree and print the result.
    if (auto weight = find_weight_MST(graph); weight.has_value()) {
        std::cout << weight.value() << std::endl;
    } else {
        std::cout << "Oops! I did it again" << std::endl;
    }

    return 0;
}
