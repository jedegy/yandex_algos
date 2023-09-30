// https://contest.yandex.ru/contest/25069/problems/F/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<vector<int>> graph;

int min_dist_between_two_vertices(int start, int end) {
    vector<int> dist(graph.size(), INT_MAX);
    dist[start] = 0;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            if (dist[neighbor] == INT_MAX) {
                dist[neighbor] = dist[current] + 1;
                q.push(neighbor);
            }
        }
    }
    return dist[end] == INT_MAX ? -1 : dist[end];
}


int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start, end;
    cin >> start >> end;

    cout << min_dist_between_two_vertices(--start, --end) << endl;

    return 0;
}
