// https://contest.yandex.ru/contest/22449/problems/C/
#include <iostream>
#include <vector>
#include "algorithm"

using namespace std;

int main() {
    int n,m;

    cin>>n;
    cin>>m;

    vector<vector<int>> matrix(n, vector<int>(m));
    vector<int> neighbors;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int row, col;
    cin >> row >> col;

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

    for (int neighbor : neighbors) {
        cout << neighbor << " ";
    }
    cout << endl;

    return 0;
}
