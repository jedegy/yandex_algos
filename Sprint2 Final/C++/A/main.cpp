/*
-- WORKING PRINCIPLE --
I have implemented a template class called `Deque` (Double-Ended Queue) using a circular buffer based on a dynamic array.
The deque utilizes a dynamically allocated array to store elements and supports operations to add and remove elements from both ends.

-- PROOF OF CORRECTNESS --
The code handles cases when the deque is empty or full correctly.
The methods `push_front` and `push_back` add elements to the corresponding ends of the deque.
The methods `pop_front` and `pop_back` remove elements from the front and back ends, respectively.
If an attempt is made to extract an element from an empty deque, a custom exception named `EmptyDeque` is thrown.

The circular buffer technique is used to handle the wrap-around behavior of the indices in the dynamic array.
When adding elements to the front of the deque, the `head_id` is adjusted using the formula: head_id = (head_id - 1 + max_deq_size) % max_deq_size.
When adding elements to the back of the deque, the `tail_id` is adjusted using the formula: tail_id = (tail_id + 1) % max_deq_size.
This ensures that the indices stay within the valid range, and elements are stored in a circular manner within the array.

-- TIME COMPLEXITY --
Adding an element to the front or back of the deque takes O(1) time because it requires only modifying indices and writing the element to the array.
Removing an element from the front or back of the deque also takes O(1) time since it involves only modifying indices and retrieving the element from the array.

-- SPACE COMPLEXITY --
The `Deque` class uses a dynamically allocated array to store elements, and its size is equal to the maximum size of the deque.
As a result, the space complexity of the class is O(max_deq_size), where max_deq_size is the maximum size of the deque.

Successfully report: https://contest.yandex.ru/contest/22781/run-report/89326715/
*/

#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

// Custom exception class to represent an empty deque
class EmptyDeque : public std::exception
{
public:
    explicit EmptyDeque(std::string  message) : errorMessage(std::move(message)) {}

    const char* what() const noexcept override
    {
        return errorMessage.c_str();
    }

private:
    std::string errorMessage;
};

// Template class for implementing a Deque (Double-Ended Queue)
template <typename T>
class Deque {
private:
    // Pointer to dynamically allocated array to store deque elements
    T *data = nullptr;
    // Maximum size of the deque
    int max_deq_size;
    // Index of the front element
    int head_id;
    // Index of the back element
    int tail_id;
    // Current size of the deque
    int size;

    // Helper function to check if the deque is empty
    bool is_empty() const {
        return size == 0;
    }

    // Helper function to check if the deque is full
    bool is_full() const {
        return size == max_deq_size;
    }

public:
    // Constructor: creates a deque with the specified maximum size
    explicit Deque(int max_deq_size) : max_deq_size(max_deq_size), head_id(0), tail_id(0), size(0) {
        // Allocate memory for deque elements
        data = new T[max_deq_size];
    }

    // Destructor: cleans up the dynamically allocated memory
    ~Deque() {
        // Free the memory allocated for deque elements
        delete data;
    }

    // Add an element to the front of the deque
    //
    // Return:
    // 0 - indicate a successful operation
    // -1 - if the deque is full and the operation cannot be performed
    int push_front(const T &value) {
        if (is_full()) {
            return -1;
        }

        // Store the value at the front index and adjust the size
        head_id = (head_id - 1 + max_deq_size) % max_deq_size;
        data[head_id] = value;
        size++;

        return 0;
    }

    // Add an element to the back of the deque
    //
    // Return:
    // 0 - indicate a successful operation
    // -1 - if the deque is full and the operation cannot be performed
    int push_back(const T &value) {
        if (is_full()) {
            return -1;
        }

        // Store the value at the back index and adjust the size
        data[tail_id] = value;
        tail_id = (tail_id + 1) % max_deq_size;
        size++;

        return 0;
    }

    // Remove and return the front element of the deque
    T pop_front() {
        if (is_empty()) {
            // Throw an EmptyDeque exception if the deque is empty
            throw EmptyDeque("error");
        }

        // Get the front element, adjust the index, and decrease the size
        T result = data[head_id];
        head_id = (head_id + 1) % max_deq_size;
        size--;

        return result;
    }

    // Remove and return the back element of the deque
    T pop_back() {
        if (is_empty()) {
            // Throw an EmptyDeque exception if the deque is empty
            throw EmptyDeque("error");
        }

        // Get the back element, adjust the index, and decrease the size
        T result = data[(tail_id - 1 + max_deq_size) % max_deq_size];
        tail_id = (tail_id - 1 + max_deq_size) % max_deq_size;
        size--;

        return result;
    }
};

int main() {
    int n, m;
    std::string command;

    // Read the number of commands (n) and the maximum size of the deque (m)
    std::cin >> n >> m;

    // Create a Deque of integers with the specified maximum size
    Deque<int> queue = Deque<int>(m);

    std::cin.ignore();

    // Process each command
    for (int i = 0; i < n; i++) {
        getline(std::cin, command);
        std::vector<std::string> parts;
        std::istringstream iss(command);
        std::string part;

        // Split the command into parts
        while (iss >> part) {
            parts.push_back(part);
        }

        // Perform the corresponding operation based on the command
        if (parts[0] == "push_back") {
            int number = stoi(parts[1]);
            if (queue.push_back(number)) {
                std::cout << "error" << std::endl;
            }
        } else if (parts[0] == "push_front") {
            int number = stoi(parts[1]);
            if (queue.push_front(number)) {
                std::cout << "error" << std::endl;
            }
        } else if (parts[0] == "pop_front") {
            try {
                std::cout << queue.pop_front() << std::endl;
            } catch (const EmptyDeque &ex) {
                std::cout << ex.what() << std::endl;
            }
        } else if (parts[0] == "pop_back") {
            try {
                std::cout << queue.pop_back() << std::endl;
            } catch (const EmptyDeque &ex) {
                std::cout << ex.what() << std::endl;
            }
        }
    }
}