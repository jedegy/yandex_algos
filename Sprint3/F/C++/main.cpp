// https://contest.yandex.ru/contest/23638/problems/F/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> triangle_sides(n);

    for (int i = 0; i < n; i++) {
        std::cin >> triangle_sides[i];
    }

    std::sort(triangle_sides.begin(), triangle_sides.end());

    int perimeter = 0;
    for (int i = 2; i < n; i++) {
        if (triangle_sides[i] < triangle_sides[i - 2] + triangle_sides[i - 1]) {
            perimeter = std::max(perimeter, triangle_sides[i] + triangle_sides[i - 2] + triangle_sides[i - 1]);
        }
    }

    std::cout << perimeter << std::endl;

    return 0;
}