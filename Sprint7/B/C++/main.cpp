// https://contest.yandex.ru/contest/25596/problems/B/
#include <iostream>
#include <vector>
#include <algorithm>

struct Lesson {
    double start, end;
};

bool compare(const Lesson &a, const Lesson &b) {
    if (a.end == b.end) {
        return a.start < b.start;
    } else {
        return a.end < b.end;
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Lesson> lessons(n);
    for (int i = 0; i < n; i++) {
        std::cin >> lessons[i].start >> lessons[i].end;
    }

    std::sort(lessons.begin(), lessons.end(), compare);

    std::vector<Lesson> result;
    double last_end = -1.0;

    for (const auto &lesson: lessons) {
        if (lesson.start >= last_end) {
            result.push_back(lesson);
            last_end = lesson.end;
        }
    }

    std::cout << result.size() << std::endl;
    for (const auto &lesson: result) {
        std::cout << lesson.start << ' ' << lesson.end << std::endl;
    }

    return 0;
}
