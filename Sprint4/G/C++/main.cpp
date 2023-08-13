// https://contest.yandex.ru/contest/23991/problems/G/
#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::unordered_map<int, int> map;
    std::cin >> n;

    std::vector<int> rounds(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> rounds[i];
        if (rounds[i] == 0) {
            rounds[i] = -1;
        }
    }

    map[0] = -1;
    int summ = 0, result = 0;
    for (int i = 0; i < n; ++i) {
        summ += rounds[i];
        if (map.find(summ) == map.end()) {
            map[summ] = i;
        } else {
            result = std::max(result, i - map[summ]);
        }
    }

    std::cout << result << std::endl;
    return 0;
}