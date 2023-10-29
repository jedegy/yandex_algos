// https://contest.yandex.ru/contest/26131/problems/E/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;

    int n;
    std::cin >> n;

    std::vector<std::pair<std::string, int>> strs(n);
    for (int i = 0; i < n; ++i) {
        std::string t;
        int k;
        std::cin >> t >> k;
        strs[i] = {t, k};
    }

    std::sort(strs.begin(), strs.end(), [](std::pair<std::string, int> a, std::pair<std::string, int> b) {return a.second < b.second;});

    std::string result;
    int prev = 0;
    for (auto &str : strs) {
        int pos = str.second;
        result += s.substr(prev, pos - prev) + str.first;
        prev = pos;
    }

    result += s.substr(prev);

    std::cout << result << std::endl;
}