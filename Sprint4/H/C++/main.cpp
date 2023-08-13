// https://contest.yandex.ru/contest/23991/problems/H/
#include <iostream>
#include <unordered_map>
#include <string>

bool is_equal(const std::string &s, const std::string &t) {
    if (s.length() != t.length()) {
        return false;
    }

    std::unordered_map<char, char> s_t;
    std::unordered_map<char, char> t_s;

    for (int i = 0; i < s.length(); ++i) {
        if (s_t.find(s[i]) == s_t.end()) {
            s_t[s[i]] = t[i];
        } else if (s_t[s[i]] != t[i]) {
            return false;
        }

        if (t_s.find(t[i]) == t_s.end()) {
            t_s[t[i]] = s[i];
        } else if (t_s[t[i]] != s[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    std::string s, t;
    std::cin >> s;
    std::cin >> t;

    if (is_equal(s, t)) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

    return 0;
}
