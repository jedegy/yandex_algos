// https://contest.yandex.ru/contest/25596/problems/O/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<int> in_degree(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        in_degree[v]++;
    }

    int a, b;
    cin >> a >> b;
    a--; b--;

    vector<long long> dp(n, 0);
    dp[a] = 1;

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : graph[curr]) {
            dp[neighbor] = (dp[neighbor] + dp[curr]) % MOD;
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    cout << dp[b] << endl;

    return 0;
}
