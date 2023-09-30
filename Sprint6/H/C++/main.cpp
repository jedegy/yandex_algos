// https://contest.yandex.ru/contest/25069/problems/H/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> time_in;
vector<int> time_out;
int timer;

void dfs(int v) {
    visited[v] = true;
    time_in[v] = timer++;
    for (int u : graph[v]) {
        if (!visited[u])
            dfs(u);
    }
    time_out[v] = timer++;
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n);
    visited.resize(n, false);
    time_in.resize(n, -1);
    time_out.resize(n, -1);
    timer = 0;

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from - 1].push_back(to - 1);
    }

    for (auto &neighbors : graph) {
        sort(neighbors.begin(), neighbors.end());
    }

    dfs(0);

    for (int i = 0; i < n; i++) {
        cout << time_in[i] << " " << time_out[i] << endl;
    }

    return 0;
}
