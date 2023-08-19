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
*/

use std::collections::hash_map::DefaultHasher;
use std::hash::{Hash, Hasher};

const TABLE_SIZE: usize = 1000003;

/// Represents a single entry in the hash table.
#[derive(Clone, Default)]
struct Entry<K, T> {
    /// The key of the entry.
    key: Option<K>,
    /// The value associated with the key.
    value: Option<T>,
    /// Indicates whether the entry has been deleted.
    deleted: bool,
}

/// Represents a hash table with keys of type K and values of type T.
pub struct HashTable<K, T>
where
    K: Eq + Hash + Clone + Default,
    T: Clone + Default,
{
    table: Vec<Entry<K, T>>,
}

impl<K, T> HashTable<K, T>
where
    K: Eq + Hash + Clone + Default,
    T: Clone + Default,
{
    /// Creates a new hash table.
    pub fn new() -> Self {
        Self {
            table: vec![Entry::default(); TABLE_SIZE],
        }
    }

    /// Hash function to calculate the index of a given key.
    fn hash(key: &K) -> usize {
        let mut hasher = DefaultHasher::new();
        key.hash(&mut hasher);
        hasher.finish() as usize % TABLE_SIZE
    }

    /// Computes the next index for quadratic probing.
    fn next_probe(init_idx: usize, i: usize) -> usize {
        (init_idx + i * i) % TABLE_SIZE
    }

    /// Inserts or updates a key-value pair into the hash table.
    ///
    /// # Arguments
    ///
    /// * `key` - The key to insert or update.
    /// * `value` - The value associated with the key.
    pub fn put(&mut self, key: K, value: T) {
        let idx = Self::hash(&key);
        let mut i = 1;

        let mut probe_idx = idx;
        while self.table[probe_idx].key.is_some()
            && self.table[probe_idx].key != Some(key.clone())
            && !self.table[probe_idx].deleted
        {
            probe_idx = Self::next_probe(idx, i);
            i += 1;
        }

        self.table[probe_idx].key = Some(key);
        self.table[probe_idx].value = Some(value);
        self.table[probe_idx].deleted = false;
    }

    /// Retrieves the value associated with a given key, if it exists.
    ///
    /// # Arguments
    ///
    /// * `key` - The key to look for.
    ///
    /// # Returns
    ///
    /// An Option containing the value if the key exists, or None if it does not.
    pub fn get(&self, key: K) -> Option<T> {
        let idx = Self::hash(&key);
        let mut i = 1;

        let mut probe_idx = idx;
        while self.table[probe_idx].key.is_some() {
            if !self.table[probe_idx].deleted && self.table[probe_idx].key == Some(key.clone()) {
                return self.table[probe_idx].value.clone();
            }
            probe_idx = Self::next_probe(idx, i);
            i += 1;
        }

        None
    }

    /// Removes a key-value pair from the hash table, if it exists.
    ///
    /// # Arguments
    ///
    /// * `key` - The key to remove.
    ///
    /// # Returns
    ///
    /// An Option containing the value if the key exists, or None if it does not.
    pub fn remove(&mut self, key: K) -> Option<T> {
        let idx = Self::hash(&key);
        let mut i = 1;

        let mut probe_idx = idx;
        while self.table[probe_idx].key.is_some() {
            if !self.table[probe_idx].deleted && self.table[probe_idx].key == Some(key.clone()) {
                self.table[probe_idx].deleted = true;
                return self.table[probe_idx].value.clone();
            }
            probe_idx = Self::next_probe(idx, i);
            i += 1;
        }

        None
    }
}

// Helper function to read command from input
fn read_command() -> (String, i32, Option<i32>) {
    let mut input = String::new();
    std::io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");
    let mut parts = input.trim().split_whitespace();
    let command = parts.next().unwrap_or_default().to_string();
    let key = parts.next().unwrap_or_default().parse::<i32>().unwrap();

    let value = match parts.next() {
        Some(value) => Some(value.parse::<i32>().unwrap()),
        None => None,
    };
    (command, key, value)
}

fn main() {
    let mut input = String::new();
    std::io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");
    let n = input.trim().parse::<usize>().unwrap();

    let mut hashtable = HashTable::<i32, i32>::new();

    for _ in 0..n {
        let (command, key, value) = read_command();

        match command.as_str() {
            "put" => {
                if let Some(val) = value {
                    hashtable.put(key, val);
                }
            }
            "get" => match hashtable.get(key) {
                Some(value) => println!("{}", value),
                None => println!("None"),
            },
            "delete" => match hashtable.remove(key) {
                Some(value) => println!("{}", value),
                None => println!("None"),
            },
            _ => {}
        }
    }
}
