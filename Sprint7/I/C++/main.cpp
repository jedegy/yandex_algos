// https://contest.yandex.ru/contest/25596/problems/I/
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

    std::string path;
    int i = 0, j = m - 1;
    while (i < n - 1 || j > 0) {
        int mi = (i == n - 1) ? -1 : dp[i + 1][j];
        int mj = (j == 0) ? -1 : dp[i][j - 1];
        if (mi > mj) {
            path.push_back('U');
            if (i != n - 1) {
                ++i;
            }
        } else {
            path.push_back('R');
            if (j != 0) {
                --j;
            }
        }
    }

    std::reverse(path.begin(), path.end());
    std::cout << path << std::endl;

    return 0;
}
