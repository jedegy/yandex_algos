// https://contest.yandex.ru/contest/23638/problems/E/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> prices(n);

    for (int i = 0; i < n; i++) {
        std::cin >> prices[i];
    }

    if (n == 1) {
        if (k > prices[0]) {
            std::cout << 1 << std::endl;
            return 0;
        } else {
            std::cout << 0 << std::endl;
            return 0;
        }
    }

    std::sort(prices.begin(), prices.end());
    for (int i = 0; i < n; i++) {
        if (k < 0) {
            std::cout << i - 1 << std::endl;
            return 0;
        }
        k -= prices[i];
    }
    std::cout << n - 1 << std::endl;

    return 0;
}