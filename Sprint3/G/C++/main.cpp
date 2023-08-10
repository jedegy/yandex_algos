// https://contest.yandex.ru/contest/23638/problems/G/
#include <iostream>
#include <vector>

int main() {
    int n, color;
    std::vector<int> clothes(3);
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> color;
        clothes[color]++;
    }

    for (int i = 0; i < clothes.size(); i++) {
        for (int j = 0; j < clothes[i]; j++) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}