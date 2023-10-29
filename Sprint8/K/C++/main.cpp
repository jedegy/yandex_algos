// https://contest.yandex.ru/contest/26131/problems/K/
#include <iostream>
#include <string>

std::string refactor(const std::string &s) {
    const std::string allowed_chars = "bdfhjlnprtvxz";
    std::string result;

    for (char c : s) {
        if (allowed_chars.find(c) != std::string::npos) {
            result.push_back(c);
        }
    }

    return result;
}

int main() {
    std::string a, b;
    std::cin >> a >> b;

    a = refactor(a);
    b = refactor(b);

    if (a.compare(b) == 0) {
        std::cout << 0 << std::endl;
    } else if (a.compare(b) < 0) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << 1 << std::endl;
    }

    return 0;
}
