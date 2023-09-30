// https://contest.yandex.ru/contest/25069/problems/A/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> matrix(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        matrix[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i) {
        std::sort(matrix[i].begin(), matrix[i].end());
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << matrix[i].size();
        for (const int &v : matrix[i]) {
            std::cout << " " << v;
        }
        std::cout << std::endl;
    }

    return 0;
}
