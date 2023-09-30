// https://contest.yandex.ru/contest/25069/problems/L/
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    std::vector<Node*> to;
};

typedef std::vector<Node*> NodeList;

int main() {
    int n, m;
    cin >> n >> m;

    NodeList list(n, nullptr);
    for (int i = 0; i < n; ++i) {
        list[i] = new Node{i, {}};
    }


    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (u != v) {
            list[u]->to.emplace_back(list[v]);
            list[v]->to.emplace_back(list[u]);
        }
    }

    for (auto &node: list) {
        if (node == nullptr) {
            continue;
        }

        std::vector<bool> visited(n, false);
        for (auto &to_node: node->to) {
            visited[to_node->value] = true;
        }

        for (int i = 0; i < visited.size(); ++i) {
            if (i == 0 || i == node->value) {
                continue;
            }
            if (!visited[i]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;

    return 0;
}
