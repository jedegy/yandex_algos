// https://contest.yandex.ru/contest/23991/problems/F/
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::map<std::string, std::vector<int>> map;

    for (int i = 0; i < n; ++i) {
        std::string str;
        std::cin >> str;
        std::sort(str.begin(), str.end());
        map[str].push_back(i);
    }

    std::vector<std::tuple<int, std::vector<int>>> result;
    result.reserve(map.size());
    for (const auto &[key, vec]: map) {
        result.emplace_back(vec.front(), vec);
    }

    std::sort(result.begin(), result.end());

    for (const auto &t: result) {
        for (int elem: std::get<1>(t)) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}