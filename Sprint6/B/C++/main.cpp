// https://contest.yandex.ru/contest/25069/problems/B/
#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        matrix[u - 1][v - 1] = 1;
    }

    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
