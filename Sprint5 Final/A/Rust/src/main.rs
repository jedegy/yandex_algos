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
2. The `Heap::sort` function has a time complexity of O(N log N), where `N` is the number of participants.
   This is because each heap pop operation takes O(log N) time and we perform N such operations.

-- SPACE COMPLEXITY --
The space complexity of the program is O(N), where `N` is the number of participants.
This is because we store all participants in a heap data structure and an additional sorted vector.
*/

use std::io::{self, BufRead};

#[derive(Debug, Eq, PartialEq)]
struct Participant {
    login: String,
    tasks: i32,
    penalty: i32,
}

impl Ord for Participant {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        other
            .tasks
            .cmp(&self.tasks)
            .then_with(|| self.penalty.cmp(&other.penalty))
            .then_with(|| self.login.cmp(&other.login))
    }
}

impl PartialOrd for Participant {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

struct Heap {
    heap: Vec<Participant>,
}

impl Heap {
    fn new(participants: Vec<Participant>) -> Self {
        let mut heap = Heap { heap: participants };
        for i in (0..heap.heap.len() / 2).rev() {
            heap.shift_down(i);
        }
        heap
    }

    fn shift_down(&mut self, idx: usize) {
        let len = self.heap.len();
        let mut idx_max = idx;
        let left = 2 * idx + 1;
        let right = 2 * idx + 2;

        if left < len && self.heap[left] < self.heap[idx_max] {
            idx_max = left;
        }

        if right < len && self.heap[right] < self.heap[idx_max] {
            idx_max = right;
        }

        if idx_max != idx {
            self.heap.swap(idx, idx_max);
            self.shift_down(idx_max);
        }
    }

    fn pop_max(&mut self) -> Participant {
        let mut last = self.heap.pop().unwrap();
        if let Some(first) = self.heap.first_mut() {
            std::mem::swap(first, &mut last);
            self.shift_down(0);
        }
        last
    }

    fn sort(mut self) -> Vec<Participant> {
        let mut result = Vec::new();
        while !self.heap.is_empty() {
            result.push(self.pop_max());
        }
        result
    }
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    let n: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();

    let mut participants = Vec::new();

    for _ in 0..n {
        let line = lines.next().unwrap().unwrap();
        let parts: Vec<_> = line.split_whitespace().collect();
        let login = parts[0].to_string();
        let tasks = parts[1].parse().unwrap();
        let penalty = parts[2].parse().unwrap();

        participants.push(Participant {
            login,
            tasks,
            penalty,
        });
    }

    let heap = Heap::new(participants);

    for p in heap.sort() {
        println!("{}", p.login);
    }
}
