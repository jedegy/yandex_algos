// https://contest.yandex.ru/contest/23991/problems/D/
#include <iostream>
#include <map>
#include <vector>

int main() {
    int n;
    std::map<std::string, int> map;
    std::cin >> n;

    std::vector<std::string> names(n);
    std::cin.ignore();

    for (int i = 0; i < n; i++) {
        std::string name;
        std::getline(std::cin, name);
        names[i] = name;

        map[name]++;
    }

    for (const auto &name: names) {
        int value = map[name];
        if (value) {
            std::cout << name << std::endl;
            map[name] = 0;
        }
    }

    return 0;
}