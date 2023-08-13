// https://contest.yandex.ru/contest/23991/problems/E/
#include <iostream>
#include <unordered_set>

int main() {
    std::string s;
    std::cin >> s;

    std::unordered_set<char> set;
    int result = 0;
    int left = 0, right = 0;

    while (right < s.size()) {
        if (set.find(s[right]) == set.end()) {
            set.insert(s[right]);
            result = std::max(result, right - left + 1);
            right++;
        } else {
            set.erase(s[left]);
            left++;
        }
    }

    std::cout << result << std::endl;

    return 0;
}