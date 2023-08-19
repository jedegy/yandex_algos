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

Link to successful report: https://contest.yandex.ru/contest/24414/run-report/89727847/
*/
#include <iostream>
#include <vector>
#include <optional>

const int TABLE_SIZE = 1000003;

// Represents a single entry in the hash table
template <typename K, typename T>
struct Entry {
    // The key of the entry
    K key;
    // The value associated with the key
    T value;
    // Indicates whether the entry has been deleted
    bool deleted;
    Entry() : key(K()), value(T()), deleted(false) {}
};

template <typename K, typename T>
class HashTable {
private:
    std::vector<Entry<K, T>> table;

    // Hash function to calculate the index of a given key.
    int hash(K key) {
        return std::hash<K>{}(key) % TABLE_SIZE;
    }

    // Checks if a given key is considered empty.
    bool is_empty_key(K key) {
        return key == K();
    }

    // Computes the next index for quadratic probing.
    int next_probe(int init_idx, int i) {
        return (init_idx + i * i) % TABLE_SIZE;
    }
    
public:
    HashTable() : table(TABLE_SIZE) {}

    // Inserts or updates a key-value pair into the hash table.
    void put(K key, T value) {
        int idx = hash(key);
        int init_idx = idx;
        int i = 1;

        // Find an index to insert or update the key-value pair.
        // Uses quadratic probing to resolve collisions.
        while (!is_empty_key(table[idx].key) && table[idx].key != key && !table[idx].deleted) {
            idx = next_probe(init_idx, i);
            i++;
        }

        // Insert or update the key-value pair at the found index
        table[idx].key = key;
        table[idx].value = value;
        table[idx].deleted = false;
    }

    // Retrieves the value associated with a given key, if it exists.
    std::optional<T> get(int key) {
        int idx = hash(key);
        int init_idx = idx;
        int i = 1;

        // Look for the key in the hash table using quadratic probing
        while (!is_empty_key(table[idx].key)) {
            if (!table[idx].deleted && table[idx].key == key) {
                return table[idx].value;
            }
            idx = next_probe(init_idx, i);
            i++;
        }

        // Return an empty optional if the key is not found
        return {};
    }

    // Removes a key-value pair from the hash table, if it exists.
    std::optional<T> remove(int key) {
        int idx = hash(key);
        int init_idx = idx;
        int i = 1;

        // Look for the key in the hash table using quadratic probing
        while (!is_empty_key(table[idx].key)) {
            if (!table[idx].deleted && table[idx].key == key) {
                // Mark the entry as deleted and return its value
                table[idx].deleted = true;
                return  table[idx].value;
            }
            idx = next_probe(init_idx, i);
            i++;
        }

        // Return an empty optional if the key is not found
        return {};
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
