// https://contest.yandex.ru/contest/25596/problems/F/
#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> ways(n + 1, 0);
    ways[1] = 1;

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= k && j <= i; ++j) {
            ways[i] = (ways[i] + ways[i - j]) % MOD;
        }
    }

    std::cout << ways[n] << std::endl;

    return 0;
}