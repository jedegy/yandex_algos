// https://contest.yandex.ru/contest/25069/problems/J/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> g;
vector<bool> visited;
stack<int> result;

void dfs(int start_v) {
    visited[start_v] = true;
    for (int u : g[start_v]) {
        if (!visited[u])
            dfs(u);
    }
    result.push(start_v);
}

int main() {
    int n, m;
    cin >> n >> m;

    g.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        g[from - 1].push_back(to - 1);
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    
    while (!result.empty()) {
        cout << result.top() + 1 << " ";
        result.pop();
    }
    cout << endl;

    return 0;
}
