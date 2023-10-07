// https://contest.yandex.ru/contest/25596/problems/E/
#include <iostream>
#include <vector>
#include <algorithm>

const int DP_MAX = 1e5;

int main() {
    int x, k;
    std::cin >> x >> k;

    std::vector<int> denominations(k);
    for (int i = 0; i < k; i++) {
        std::cin >> denominations[i];
    }

    std::vector<int> dp(x + 1, DP_MAX);
    dp[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (int d : denominations) {
            if (i - d >= 0) {
                dp[i] = std::min(dp[i], dp[i - d] + 1);
            }
        }
    }

    if (dp[x] == DP_MAX) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << dp[x] << std::endl;
    }

    return 0;
}
