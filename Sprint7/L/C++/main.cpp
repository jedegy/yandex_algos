// https://contest.yandex.ru/contest/25596/problems/L/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> weights(n);

    for (int i = 0; i < n; i++) {
        std::cin >> weights[i];
    }

    std::vector<int> dp(m + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = m; j >= weights[i]; j--) {
            dp[j] = std::max(dp[j], dp[j - weights[i]] + weights[i]);
        }
    }

    std::cout << dp[m] << std::endl;

    return 0;
}
