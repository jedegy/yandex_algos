// https://contest.yandex.ru/contest/23638/problems/N/
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::tuple<int, int>> gardens;

    for (int i = 0; i < n; i++) {
        int start, end;
        std::cin >> start >> end;
        std::tuple<int, int> range(start, end);
        gardens.push_back(range);
    }

    std::sort(gardens.begin(), gardens.end());

    std::vector<std::tuple<int, int>> result;
    if (gardens.size() == 1) {
        std::cout << std::get<0>(gardens[0]) << " " << std::get<1>(gardens[0]) << std::endl;
    } else {
        int i = 0, j;
        while (i < gardens.size()) {
            int start = std::get<0>(gardens[i]);
            int end = std::get<1>(gardens[i]);

            for (j = i + 1; j < gardens.size(); j++) {
                int next_start = std::get<0>(gardens[j]);
                if (next_start <= end) {
                    end = std::max(end, std::get<1>(gardens[j]));
                } else
                    break;
            }
            std::tuple<int, int> range(start, end);
            result.push_back(range);
            i = j;
        }
    }

    for (auto range: result) {
        std::cout << std::get<0>(range) << " " << std::get<1>(range) << std::endl;
    }
}