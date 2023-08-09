// https://contest.yandex.ru/contest/22779/problems/A/
#include <iostream>
#include <vector>

std::vector<std::vector<int>> transposition(std::vector<std::vector<int>>& matrix) {
    std::vector<std::vector<int>> transposed(matrix[0].size(), std::vector<int>(matrix.size()));

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    if (!n || !m) {
        return 0;
    }

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<std::vector<int>> transposed = transposition(matrix);
    for (const std::vector<int> &row: transposed) {
        for (int elem: row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}