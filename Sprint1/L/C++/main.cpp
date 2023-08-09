// https://contest.yandex.ru/contest/22449/problems/L/
#include <iostream>
#include <string>
#include <array>

int main() {
    std::array<short, 26> alphabet = {};
    std::string s, t;
    std::cin >> s >> t;

    for (char character: s) {
        alphabet[character - 'a'] += 1;
    }
    for (char character: t) {
        alphabet[character - 'a'] += 1;
    }

    for (unsigned int i = 0; i < 26; i++) {
        if (alphabet[i] % 2 != 0) {
            std::cout << (char) (i + 'a') << std::endl;
            break;
        }
    }
}
