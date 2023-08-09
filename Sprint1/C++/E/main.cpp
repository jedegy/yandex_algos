// https://contest.yandex.ru/contest/22449/problems/E/
#include <iostream>
#include <string>
#include <sstream>

int main() {
    int l;
    std::cin >> l;
    std::cin.ignore();

    std::string line;

    std::getline(std::cin, line);

    std::istringstream iss(line);
    std::string word;

    unsigned int max_len = 0;
    std::string max_len_word;

    while (iss >> word) {
        if (word.length() > max_len) {
            max_len = word.length();
            max_len_word = word;
        }
    }

    std::cout << max_len_word << std::endl;
    std::cout << max_len << std::endl;

    return 0;
}
