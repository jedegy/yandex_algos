// https://contest.yandex.ru/contest/26131/problems/D/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> strs(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> strs[i];
    }

    if (n == 1) {
        std::cout << strs[0].length() << std::endl;
        return 0;
    }

    std::sort(strs.begin(), strs.end());

    std::string& first = strs[0];
    std::string& last = strs[n - 1];
    int i = 0;

    while (i < first.length() && i < last.length() && first[i] == last[i]) {
        i++;
    }

    std::cout << i << std::endl;
}