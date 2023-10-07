// https://contest.yandex.ru/contest/25596/problems/M/
#include <iostream>
#include <vector>

int main() {
    int n, M;
    std::cin >> n >> M;

    std::vector<int> m(n + 1), c(n + 1);
    for(int i = 1; i <= n; ++i) {
        std::cin >> m[i] >> c[i];
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(M + 1, 0));

    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= M; ++j) {
            dp[i][j] = dp[i - 1][j];
            if(j >= m[i]) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - m[i]] + c[i]);
            }
        }
    }

    std::vector<int> result;
    int weight = M;

    for(int i = n; i >= 1; --i) {
        if(dp[i][weight] != dp[i-1][weight]) {
            result.push_back(i);
            weight -= m[i];
        }
    }

    std::cout << result.size() << std::endl;
    for(int i = result.size() - 1; i >= 0; --i) {
        std::cout << result[i] << " ";
    }

    return 0;
}
