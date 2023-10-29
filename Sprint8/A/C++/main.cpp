// https://contest.yandex.ru/contest/26131/problems/A/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

int main() {
    std::string s;
    getline(std::cin, s);
    std::istringstream iss(s);

    std::vector<std::string> parts(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{});
    std::reverse(parts.begin(), parts.end());

    for (const auto& part: parts) {
        std::cout << part << " ";
    }

    std::cout << std::endl;
}