// https://contest.yandex.ru/contest/23638/problems/J/
#include <iostream>
#include <vector>

void print_array(std::vector<int>& array) {
    for (int elem: array) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void bubble_sort(std::vector<int>& array) {
    for (int j = 1; j < array.size(); j++) {
        bool flag = false;
        for (int i = 0; i < array.size() - j; i++) {
            if (array[i] > array[i + 1]) {
                std::swap(array[i], array[i + 1]);
                flag = true;
            }
        }
        if (!flag) {
            if (j == 1) {
                print_array(array);
            }
            break;
        } else
            print_array(array);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> array(n);

    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    bubble_sort(array);
}