// https://contest.yandex.ru/contest/22449/problems/D/
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int* temperature = new int[n];
    int chaotic = 0;

    for (int i = 0; i < n; i++) {
        cin >> temperature[i];
        if ((i > 1) && (temperature[i - 1] > temperature[i]) && (temperature[i - 1] > temperature[i - 2])) {
            chaotic++;
        }
    }

    if (n == 1) {
        cout<<1;
        return 0;
    }


    if (temperature[0] > temperature[1]) {
        chaotic++;
    }

    if (temperature[n - 1] > temperature[n - 2]) {
        chaotic++;
    }

    delete[] temperature;

    cout<<chaotic;

    return 0;
}
