// https://contest.yandex.ru/contest/25069/problems/D/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(int start_v, const vector<vector<int>> &g) {
    int n = g.size() - 1;
    vector<bool> visited(n + 1, false);
    queue<int> q;

    q.push(start_v);
    visited[start_v] = true;

    while (!q.empty()) {
        int current_v = q.front();
        q.pop();

        cout << current_v << " ";

        for (int neighbor : g[current_v]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);

    // Чтение рёбер
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        sort(g[i].begin(), g[i].end());
    }

    int start_v;
    cin >> start_v;

    bfs(start_v, g);

    return 0;
}
