// https://contest.yandex.ru/contest/23638/problems/D/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;

    std::cin >> n;
    std::vector<int> factors(n);

    for (int i = 0; i < n; i++) {
        std::cin >> factors[i];
    }

    std::cin >> m;
    std::vector<int> cookie_sizes(m);

    for (int i = 0; i < m; i++) {
        std::cin >> cookie_sizes[i];
    }

    sort(factors.begin(), factors.end());
    sort(cookie_sizes.begin(), cookie_sizes.end());

    int child = 0;
    int cookie = 0;

    while (child < factors.size() && cookie < cookie_sizes.size()) {
        if (factors[child] <= cookie_sizes[cookie]) {
            child++;
        }
        cookie++;
    }
    std::cout << child << std::endl;
}