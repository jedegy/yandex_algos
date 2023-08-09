// https://contest.yandex.ru/contest/22450/problems/B/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

const short FIELD_SIZE = 4;
const short MAX_GAME_NUMBER = 9;

int game_score(short k, std::vector<std::string>& field) {
    std::vector<int> counts(MAX_GAME_NUMBER + 1, 0);
    int score = 0;

    for (std::string &row: field) {
        for (char val: row) {
            if (val >= '1' && val <= '9') {
                counts[val - '0']++;
            }
        }
    }

    for (int t = 1; t <= MAX_GAME_NUMBER; t++) {
        if (counts[t] && counts[t] <= 2 * k) {
            score++;
        }
    }

    return score;
}

int main() {
    short k;
    std::vector<std::string> field;

    std::cin >> k;
    std::cin.ignore();

    std::string line;
    for (short i = 0; i < FIELD_SIZE; i++) {
        std::getline(std::cin, line);
        field.push_back(line);
    }

    std::cout << game_score(k, field) << std::endl;

    return 0;
}
