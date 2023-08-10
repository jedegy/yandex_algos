// https://contest.yandex.ru/contest/23638/problems/M/
#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n;
    std::cin >> m;

    std::vector<int> north_nums(n);
    std::vector<int> south_nums(m);

    for (int i = 0; i < n; i++) {
        std::cin >> north_nums[i];
    }

    for (int i = 0; i < m; i++) {
        std::cin >> south_nums[i];
    }

    std::vector<int> result;
    auto left = north_nums.begin();
    auto right = south_nums.begin();

    while (left < north_nums.end() && right < south_nums.end()) {
        if (*left <= *right) {
            result.push_back(*left);
            left++;
        } else {
            result.push_back(*right);
            right++;
        }
    }
    while (left < north_nums.end()) {
        result.push_back(*left);
        left++;
    }
    while (right < south_nums.end()) {
        result.push_back(*right);
        right++;
    }

    if (result.size() % 2 == 0) {
        std::cout << ((double) result[(result.size() - 1) / 2] + (double) result[(result.size() - 1) / 2 + 1]) / 2
                  << std::endl;
    } else {
        std::cout << result[result.size() / 2] << std::endl;
    }
}