// https://contest.yandex.ru/contest/22450/problems/
#include <iostream>
#include <vector>
#include <climits>

std::vector<unsigned int> get_distances(std::vector<int>& sites) {
    std::vector<unsigned int> distances(sites.size(), UINT_MAX);
    unsigned int last_index_empty = -sites.size();

    for (unsigned int i = 0; i < sites.size(); i++) {
        if (sites[i] == 0) {
            distances[i] = 0;
            last_index_empty = i;
        } else {
            distances[i] = i - last_index_empty;
        }
    }

    last_index_empty = 2 * sites.size();

    for (int i = (int) sites.size() - 1; i >= 0; i--) {
        if (sites[i] == 0) {
            last_index_empty = i;
        } else {
            distances[i] = std::min(distances[i], last_index_empty - i);
        }
    }

    return distances;
}

int main() {
    unsigned int n;
    std::cin >> n;

    std::vector<int> sites(n);

    for (unsigned int i = 0; i < n; i++) {
        std::cin >> sites[i];
    }

    std::vector<unsigned int> distances = get_distances(sites);

    for (unsigned int distance: distances) {
        std::cout << distance << " ";
    }
    std::cout << std::endl;

    return 0;
}
