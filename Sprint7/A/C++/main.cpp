// https://contest.yandex.ru/contest/25596/problems/A/
#include <iostream>
#include <vector>

int main() {
    int n;

    std::cin >> n;
    std::vector<int> prices(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> prices[i];
    }

    if (n <= 1) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int max_profit = 0;

    for (int i = 1; i < n; i++) {
        if (prices[i] > prices[i - 1])
            max_profit += prices[i] - prices[i - 1];
    }

    std::cout << max_profit << std::endl;

    return 0;
}