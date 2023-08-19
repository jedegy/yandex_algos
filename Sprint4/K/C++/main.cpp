// https://contest.yandex.ru/contest/23991/problems/K/
#include <iostream>
#include <vector>
#include <unordered_map>

// Size of each bucket (distance between bus stop and subway exit)
const int BUCKET_SIZE = 20;
// Offset to ensure non-negative bucket indices
const int OFFSET = 1e9;

struct Point {
    int x, y;

    Point(int x, int y) : x(x), y(y) {}
    Point() : x(0), y(0) {}

    bool operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }
};

// Hash function for Point
struct PointHash {
    size_t operator()(const Point &p) const {
        return p.x * 31 + p.y;
    }
};

int main() {
    int n, m;

    std::cin >> n;
    std::vector<Point> subway_exits(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> subway_exits[i].x >> subway_exits[i].y;
    }

    std::cin >> m;
    std::vector<Point> bus_stops(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> bus_stops[i].x >> bus_stops[i].y;
    }

    // Bucketing the bus stops
    std::unordered_map<Point, std::vector<Point>, PointHash> buckets;
    for (const auto& stop : bus_stops) {
        Point bucket{(stop.x + OFFSET) / BUCKET_SIZE, (stop.y + OFFSET) / BUCKET_SIZE};
        buckets[bucket].push_back(stop);
    }

    int best_exit = -1, max_bus_stops = 0;

    // Iterate over each subway exit and calculate number of nearby bus stops
    for (int i = 0; i < n; ++i) {
        const auto& exit = subway_exits[i];
        int count = 0;

        // Check neighboring buckets for bus stops
        for (int x = -1; x <= 1; ++x) {
            for (int y = -1; y <= 1; ++y) {
                Point bucket{((exit.x + x * BUCKET_SIZE) + OFFSET) / BUCKET_SIZE,
                             ((exit.y + y * BUCKET_SIZE) + OFFSET) / BUCKET_SIZE};

                for (const auto& stop : buckets[bucket]) {
                    int dist_x = stop.x - exit.x;
                    int dist_y = stop.y - exit.y;

                    // Check if the bus stop is within the desired range
                    if (dist_x * dist_x + dist_y * dist_y <= BUCKET_SIZE * BUCKET_SIZE) {
                        count++;
                    }
                }
            }
        }

        if (count > max_bus_stops) {
            max_bus_stops = count;
            best_exit = i;
        }
    }

    std::cout << best_exit + 1 << std::endl;

    return 0;
}
