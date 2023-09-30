// https://contest.yandex.ru/contest/25069/problems/K/
#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

void dijkstra(int vertex_s, vector<vector<pair<int, int>>> &graph, vector<int> &dist) {
    vector<bool> visited(graph.size(), false);
    dist[vertex_s] = 0;

    for (int i = 0; i < graph.size(); ++i) {
        int u = -1;

        for (int j = 0; j < graph.size(); ++j) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (dist[u] == INT_MAX) {
            break;
        }

        visited[u] = true;

        for (auto &edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<std::pair<int, int>>> graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v, l;
        cin >> u >> v >> l;
        graph[u - 1].emplace_back(v - 1, l);
        graph[v - 1].emplace_back(u - 1, l);
    }

    for (int i = 0; i < n; ++i) {
        vector<int> dist(n, INT_MAX);
        dijkstra(i, graph, dist);

        for (int j = 0; j < n; ++j) {
            if (dist[j] == INT_MAX) {
                cout << -1 << ' ';
            } else {
                cout << dist[j] << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}
