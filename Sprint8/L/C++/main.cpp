// https://contest.yandex.ru/contest/26131/problems/L/
#include <iostream>
#include <string>
#include <vector>

void prefix_function(std::string& s) {
    std::vector<int> prefix(s.length(), 0);
    for (int i = 1; i < s.length(); i++) {
        int k = prefix[i - 1];
        while (k > 0 && s[k] != s[i]) {
            k = prefix[k - 1];
        }
        if (s[k] == s[i]) {
            k += 1;
        }
        prefix[i] = k;
    }

    for (auto elem: prefix) {
        std::cout << elem << " ";
    }
}

int main() {
    std::string s;
    std::cin >> s;
    prefix_function(s);
}