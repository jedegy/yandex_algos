// https://contest.yandex.ru/contest/25069/problems/C/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int v, const vector<vector<int>>& g, vector<bool>& visited) {
    visited[v] = true;
    cout << v + 1 << " ";

    for (int neighbor : g[v]) {
        if (!visited[neighbor]) {
            dfs(neighbor, g, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (auto& neighbors : g) {
        sort(neighbors.begin(), neighbors.end());
    }

    int start_v;
    cin >> start_v;
    --start_v;

    dfs(start_v, g, visited);

    cout << endl;
    return 0;
}
