// https://contest.yandex.ru/contest/26131/problems/H/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string text, pattern, t;
    std::cin >> text >> pattern >> t;

    std::vector<int> indexes;
    std::string s = pattern + '#' + text;

    std::vector<int> prefix(s.length(), 0);
    int prefix_prev = 0;
    for (int i = 1; i < s.length(); i++) {
        int k = prefix_prev;
        while (k > 0 && s[k] != s[i]) {
            k = prefix[k - 1];
        }
        if (s[k] == s[i]) {
            k += 1;
        }
        if (i < pattern.length()) {
            prefix[i] = k;
        }
        prefix_prev = k;
        if (k == pattern.length()) {
            indexes.push_back(i - 2 * pattern.length());
        }
    }

    int diff = t.length() - pattern.length();
    int count = 0;
    for (auto index: indexes) {
        index += diff * count;
        text = text.substr(0, index) + t + text.substr(index + pattern.length(), text.length());
        count += 1;
    }

    std::cout << text << std::endl;
}