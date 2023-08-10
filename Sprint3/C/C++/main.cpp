// https://contest.yandex.ru/contest/23638/problems/C/
#include <iostream>
#include <string>

bool is_subsequence(const std::string& s, const std::string& t) {
    int i = 0, j = 0;

    while (i < s.length() && j < t.length()) {
        if (s[i] == t[j])
            i += 1;
        j += 1;
    }

    return i == s.length();
}

int main() {
    std::string s, t;
    std::getline(std::cin, s);
    std::getline(std::cin, t);

    if (is_subsequence(s, t)) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    return 0;
}