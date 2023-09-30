// https://contest.yandex.ru/contest/25069/problems/M/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool is_bipartite(vector<vector<int>>& graph) {
    vector<int> color(graph.size(), 0);
    queue<int> q;

    for (int start = 0; start < graph.size(); ++start) {
        if (color[start] == 0) {
            color[start] = 1;
            q.push(start);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : graph[u]) {
                    if (color[v] == 0) {
                        color[v] = 3 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << (is_bipartite(graph) ? "YES" : "NO") << endl;

    return 0;
}
