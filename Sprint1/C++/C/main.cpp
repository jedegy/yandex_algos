// https://contest.yandex.ru/contest/22449/problems/C/
#include <iostream>
#include <vector>
#include "algorithm"

int main() {
    int n, m;

    std::cin >> n;
    std::cin >> m;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    std::vector<int> neighbors;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }

    int row, col;
    std::cin >> row >> col;

    if (col - 1 >= 0) {
        neighbors.push_back(matrix[row][col - 1]);
    }
    if (col + 1 < m) {
        neighbors.push_back(matrix[row][col + 1]);
    }
    if (row - 1 >= 0) {
        neighbors.push_back(matrix[row - 1][col]);
    }
    if (row + 1 < n) {
        neighbors.push_back(matrix[row + 1][col]);
    }

    std::sort(neighbors.begin(), neighbors.end());

    for (int neighbor: neighbors) {
        std::cout << neighbor << " ";
    }
    std::cout << std::endl;

    return 0;
}
