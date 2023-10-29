// https://contest.yandex.ru/contest/26131/problems/I/
#include <iostream>
#include <string>
#include <vector>

std::vector<int> prefix_function(std::string& s) {
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
    return prefix;
}

int main() {
    std::string s;
    std::cin >> s;

    std::vector<int> prefix = prefix_function(s);

    if (prefix[s.size() - 1] >= s.size() / 2) {
        std::cout << s.size() / (s.size() - prefix[s.size() - 1]) << std::endl;
    } else {
        std::cout << 1 << std::endl;
    }

    return 0;
}
