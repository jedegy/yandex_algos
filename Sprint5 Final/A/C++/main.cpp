/*
-- WORKING PRINCIPLE --
This program sorts a list of participants based on the number of tasks they have completed and their penalty points.
Each participant is represented by a `Participant` struct, which holds their login, number of completed tasks, and penalty points.
The program uses a custom heap data structure to sort the participants efficiently according to these criteria.

-- PROOF OF CORRECTNESS --
The program sorts the participants using a min-heap that is implemented as an instance of the `Heap` class.
The heap is constructed with an O(N) heapify operation.
Each participant is sorted based on three key attributes: number of tasks completed, penalty points, and login.
The `Participant` struct includes a custom `operator<` to facilitate this sorting.
The `Heap::sort` function ensures that the participants are returned in sorted order, adhering to the defined sorting criteria.

-- TIME COMPLEXITY --
1. Heap construction takes O(N) time due to the heapify operation.
2. The `Heap::sort` function has a time complexity of O(N log N * M), where `N` is the number of participants and
M is the length of the longest login string among those participants.
   This is because each heap pop operation takes O(log N) time, and we perform N such operations. The comparison operation
   in pop operation also involves the login field, which has a time complexity of O(M).

-- SPACE COMPLEXITY --
The space complexity of the program is O(N), where `N` is the number of participants.
This is because we store all participants in a heap data structure and an additional sorted vector.

Link to successful report: https://contest.yandex.ru/contest/24810/run-report/90287402/
*/

#include <iostream>
#include <vector>
#include <string>
#include <tuple>

// Participant structure to store login, tasks, and penalty
struct Participant {
    std::string login;
    int tasks{};
    int penalty{};

    bool operator < (const Participant& other) const {
        return std::tie(other.tasks, penalty, login) < std::tie(tasks, other.penalty, other.login);
    }
};

// Heap class for managing and sorting Participants
class Heap {
private:
    std::vector<Participant> heap;

    // Shifts elements down the heap to maintain heap property
    void shift_down(int idx) {
        int idx_max;

        while (true) {
            idx_max = idx;
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;

            if (left < heap.size() && heap[left] < heap[idx_max]) {
                idx_max = left;
            }

            if (right < heap.size() && heap[right] < heap[idx_max]) {
                idx_max = right;
            }

            if (idx_max == idx) {
                break;
            }

            std::swap(heap[idx], heap[idx_max]);
            idx = idx_max;
        }
    }

public:
    // Constructor: Initializes heap and performs heapify operation
    explicit Heap(const std::vector<Participant>& participants) : heap(participants) {
        for (int i = static_cast<int>(participants.size()) / 2 - 1; i >= 0; --i) {
            shift_down(i);
        }
    }

    // Returns and removes the maximum element from the heap
    Participant pop_max() {
        auto result = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        shift_down(0);

        return result;
    }

    // Sorts the heap and returns the sorted vector
    std::vector<Participant> sort() {
        std::vector<Participant> result;
        while (!heap.empty()) {
            auto max = pop_max();
            result.push_back(max);
        }
        return result;
    }
};

int main() {
    int n;
    std::cin >> n;
    std::vector<Participant> participants(n);

    for (auto &participant : participants) {
        std::cin >> participant.login >> participant.tasks >> participant.penalty;
    }

    Heap heap(participants);

    for (const auto& p : heap.sort()) {
        std::cout << p.login << std::endl;
    }

    return 0;
}
