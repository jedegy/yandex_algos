/*
-- WORKING PRINCIPLE --
This program implements a hash table using quadratic probing for collision resolution. It supports the basic operations
of insertion, retrieval, and deletion of key-value pairs. Quadratic probing is a collision resolution method in open addressing
hash tables. When a collision occurs, it searches for the next available slot by incrementing the original hash index
by successive squares of a counter.

-- PROOF OF CORRECTNESS --
The hash table uses a vector to store entries, which are represented by a struct containing the key, value, and a flag indicating
whether the entry has been deleted. The `put` function inserts or updates a key-value pair by finding an available slot
using quadratic probing. The `get` function retrieves a value associated with a given key, and the `remove` function marks an entry
as deleted without actually removing it. These functions ensure that the hash table operates correctly by properly handling
collisions, deletions, and value retrievals.

-- TIME COMPLEXITY --
1. Insertion (put): The average time complexity is `O(1)`, but in the worst case (when a large number of collisions occur),
 it can go up to `O(n)`, where n is the size of the table.
2. Retrieval (get): The average time complexity is `O(1)`, but it can go up to `O(n)` in the worst case.
3. Deletion (remove): The average time complexity is `O(1)`, but it can go up to `O(n)` in the worst case.
Quadratic probing helps minimize clustering and ensures that the table is utilized efficiently, keeping the average
 time complexity close to `O(1)` for most cases.

-- SPACE COMPLEXITY --
The space complexity of the program is `O(n)`, where n is the size of the hash table. The hash table uses a fixed-size vector
to store the entries, and the size of this vector determines the maximum number of entries that the hash table can hold.
The actual space used depends on the number of entries inserted into the hash table, but it will never exceed the size of the vector.

Link to successful report: Link to successful report: https://contest.yandex.ru/contest/24414/run-report/89770066/
*/
#include <iostream>
#include <vector>
#include <optional>

const int TABLE_SIZE = 1000003;

// Represents a single entry in the hash table
template <typename K, typename T>
struct Entry {
    // The key of the entry
    K key = K();
    // The value associated with the key
    T value = T();
    // Indicates whether the entry has been deleted
    bool deleted = false;
    // Indicates whether the key is empty
    bool is_key_empty = true;
};

template <typename K, typename T>
class HashTable {
private:
    std::vector<Entry<K, T>> table;

    // Hash function to calculate the index of a given key.
    int hash(K key) {
        return std::hash<K>{}(key) % TABLE_SIZE;
    }

    // Computes the next index for quadratic probing.
    int next_probe(int init_idx, int i) {
        return (init_idx + i * i) % TABLE_SIZE;
    }

    // Look for the key in the hash table using quadratic probing
    int find_index(K key) {
        int idx = hash(key);
        int i = 1;
        int init_idx = idx;

        // Find an index to insert or update the key-value pair.
        // Uses quadratic probing to resolve collisions.
        while (!table[idx].is_key_empty) {
            if (!table[idx].deleted && table[idx].key == key) {
                return idx;
            }
            idx = next_probe(init_idx, i);
            i++;
        }

        // Return index of the first empty slot
        return idx;
    }

public:
    HashTable() : table(TABLE_SIZE) {}

    // Inserts or updates a key-value pair into the hash table.
    void put(K key, T value) {
        auto idx = find_index(key);

        // Insert or update the key-value pair at the found index
        table[idx].key = key;
        table[idx].is_key_empty = false;
        table[idx].value = value;
        table[idx].deleted = false;
    }

    // Retrieves the value associated with a given key, if it exists.
    std::optional<T> get(K key) {
        auto idx = find_index(key);
        return !table[idx].is_key_empty ? [&]{
            return std::optional<T>{table[idx].value};
        }() : std::nullopt;
    }

    // Removes a key-value pair from the hash table, if it exists.
    std::optional<T> remove(K key) {
        auto idx = find_index(key);
        return !table[idx].is_key_empty ? [&]{
            table[idx].deleted = true;
            return std::optional<T>{table[idx].value};
        }() : std::nullopt;
    }
};

int main() {
    int n;
    std::cin >> n;
    HashTable<int, int> hashtable;

    for (int i = 0; i < n; ++i) {
        std::string command;
        int key, value;
        std::cin >> command >> key;

        if (command == "put") {
            std::cin >> value;
            hashtable.put(key, value);
        } else if (command == "get") {
            auto result = hashtable.get(key);
            if (result.has_value()) {
                std::cout << result.value() << std::endl;
            } else {
                std::cout << "None" << std::endl;
            }
        } else if (command == "delete") {
            auto result = hashtable.remove(key);
            if (result.has_value()) {
                std::cout << result.value() << std::endl;
            } else {
                std::cout << "None" << std::endl;
            }
        }
    }

    return 0;
}
