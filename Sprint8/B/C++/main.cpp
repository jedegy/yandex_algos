// https://contest.yandex.ru/contest/26131/problems/B/
#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::string passport_name, base_name;
    std::cin >> passport_name >> base_name;

    int diff = passport_name.length() - base_name.length();
    if (std::abs(diff) > 1) {
        std::cout << "FAIL" << std::endl;
        return 0;
    }

    int i = 0, j = 0;
    bool insertion = false, deletion = false, change = false;
    while (i < passport_name.length() && j < base_name.length()) {
        if (passport_name[i] != base_name[j]) {
            if (!insertion && !deletion && !change && passport_name.length() < base_name.length()) {
                insertion = true;
                j++;
            } else if (!insertion && !deletion && !change && passport_name.length() > base_name.length()) {
                deletion = true;
                i++;
            } else if (!insertion && !deletion && !change && passport_name.length() == base_name.length()) {
                change = true;
            } else {
                std::cout << "FAIL" << std::endl;
                return 0;
            }
        }

        i++;
        j++;
    }

    std::cout << "OK" << std::endl;
    return 0;
}