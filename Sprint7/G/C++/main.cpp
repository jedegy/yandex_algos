// https://contest.yandex.ru/contest/25596/problems/G/
#include <iostream>
#include <vector>

int main() {
    int m, n;
    std::cin >> m >> n;

    std::vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        std::cin >> coins[i];
    }

    std::vector<long long> dp(m + 1, 0);
    dp[0] = 1;

    for(int d : coins) {
        for(int i = d; i <= m; i++) {
            dp[i] += dp[i - d];
        }
    }

    std::cout << dp[m] << std::endl;

    return 0;
}
