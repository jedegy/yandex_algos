// https://contest.yandex.ru/contest/25596/problems/H/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> field(n, std::vector<int>(m));
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char ch;
            std::cin >> ch;
            field[i][j] = ch - '0';
        }
    }

    dp[n - 1][0] = field[n - 1][0];

    for (int j = 1; j < m; ++j) {
        dp[n - 1][j] = dp[n - 1][j - 1] + field[n - 1][j];
    }

    for (int i = n - 2; i >= 0; --i) {
        dp[i][0] = dp[i + 1][0] + field[i][0];
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = field[i][j] + std::max(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    std::cout << dp[0][m - 1] << std::endl;

    return 0;
}
