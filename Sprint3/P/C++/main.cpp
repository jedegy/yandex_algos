// https://contest.yandex.ru/contest/23638/problems/P/
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }

    int result = 0;
    int max = -1;
    for (int i = 0; i < n; i++) {
        max = std::max(max, numbers[i]);
        if (max == i) {
            result++;
            max = -1;
        }
    }

    std::cout << result << std::endl;
}