// https://contest.yandex.ru/contest/25069/problems/E/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int v, vector<vector<int>>& g, vector<bool>& visited, vector<int>& component) {
    visited[v] = true;
    component.push_back(v);
    for (const auto& u : g[v]) {
        if (!visited[u]) {
            dfs(u, g, visited, component);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    vector<bool> visited(n, false);
    vector<vector<int>> components;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, g, visited, component);
            sort(component.begin(), component.end());
            components.push_back(component);
        }
    }

    cout << components.size() << endl;
    for (const auto& component : components) {
        for (const auto& v : component) {
            cout << v + 1 << ' ';
        }
        cout << endl;
    }

    return 0;
}
