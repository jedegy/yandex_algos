// https://contest.yandex.ru/contest/25069/problems/G/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(int start, vector<vector<int>>& g) {
    int n = int(g.size());
    vector<int> distance(n, -1);
    queue<int> q;

    q.push(start);
    distance[start] = 0;
    int max = 0;

    while (!q.empty()) {
        int current_v = q.front();
        q.pop();

        for (int neighbor: g[current_v]) {
            if (distance[neighbor] == -1) {
                q.push(neighbor);
                distance[neighbor] = distance[current_v] + 1;
                max = std::max(max, distance[neighbor]);
            }
        }
    }

    return max;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    int s;
    cin >> s;

    cout << bfs(s - 1, graph) << endl;

    return 0;
}
