// https://contest.yandex.ru/contest/23638/problems/H/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int first_digit(int num) {
    while (num >= 10) {
        num /= 10;
    }
    return num;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> buckets[10];

    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        buckets[first_digit(num)].push_back(std::to_string(num));
    }

    for (int i = 9; i >= 0; --i) {
        std::sort(buckets[i].begin(), buckets[i].end(), [](const std::string &a, const std::string &b) {
            return a + b > b + a;
        });

        for (const std::string &number: buckets[i]) {
            std::cout << number;
        }
    }

    std::cout << std::endl;
    return 0;
}