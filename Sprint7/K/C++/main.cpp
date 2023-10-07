// https://contest.yandex.ru/contest/25596/problems/K/
#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::cin >> m;
    std::vector<int> b(m);
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    std::vector<int> result_a, result_b;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            result_a.push_back(i);
            result_b.push_back(j);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    std::cout << dp[n][m] << std::endl;
    for (int k = result_a.size() - 1; k >= 0; k--) {
        std::cout << result_a[k] << " ";
    }
    std::cout << std::endl;

    for (int k = result_b.size() - 1; k >= 0; k--) {
        std::cout << result_b[k] << " ";
    }

    return 0;
}
