/*
-- WORKING PRINCIPLE --
This program implements a quick sort algorithm for sorting the results of sports programming competitions.
Each participant has a unique login, the number of solved problems and the amount of the fine.
Participants are sorted first by the number of solved problems, then by the size of the fine, and finally by login in lexicographic order.

-- PROOF OF CORRECTNESS --
The implemented algorithm correctly sorts the participants according to the specified criteria.
To compare two participants, the `compare` function is used, which takes into account all three criteria.
The quicksort algorithm is implemented using the `partition` and `quick_sort_in_place` functions.
It provides efficient and correct ordering of elements without consuming O(n) additional memory.

-- TIME COMPLEXITY --
The average time complexity of quicksort is O(n log n), but in the worst case it can be as high as O(n^2), depending on the choice of pivot.

-- SPACE COMPLEXITY --
Because it uses an in-place quicksort method that uses a recursive algorithm, so (O(n) * stack frame size) will be used in the worst case and
(O(log n) * stack frame size) will be used on average.
 */

use std::io::BufRead as _;
use std::io::Write as _;

/// Represents a contestant in a competition.
struct Participant {
    login: String,
    successfully_tasks: i32,
    fine: i32
}

impl Participant {
    /// Creates a new `Participant`.
    ///
    /// # Arguments
    ///
    /// * `login` - The login identifier for the participant.
    /// * `successfully_tasks` - The number of tasks the participant has successfully completed.
    /// * `fine` - The number of fines the participant has incurred.
    fn new(login: String, successfully_tasks: i32, fine: i32) -> Self {
        Self { login, successfully_tasks, fine}
    }
}

impl PartialEq for Participant {
    fn eq(&self, other: &Self) -> bool {
        self.successfully_tasks == other.successfully_tasks
            && self.fine == other.fine
            && self.login == other.login
    }
}

impl PartialOrd for Participant {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(if self.successfully_tasks != other.successfully_tasks {
            self.successfully_tasks.cmp(&other.successfully_tasks).reverse()
        } else if self.fine != other.fine {
            self.fine.cmp(&other.fine)
        } else {
            self.login.cmp(&other.login)
        })
    }
}

/// Partitions the slice based on the pivot for quick sort.
///
/// # Arguments
///
/// * `slice` - The slice of `Participant` to be partitioned.
///
/// # Returns
///
/// Returns the index of the pivot after partitioning.
fn partition(slice: &mut [Participant]) -> usize {
    let pivot_index = slice.len() - 1;
    let mut i = 0;
    for j in 0..slice.len() {
        if slice[j] < slice[pivot_index] {
            slice.swap(i, j);
            i += 1;
        }
    }
    slice.swap(i, pivot_index);
    i
}

/// In-place quick sort for a slice of `Participant`.
///
/// # Arguments
///
/// * `slice` - The slice of `Participant` to be sorted.
fn quick_sort_in_place(slice: &mut [Participant]) {
    if slice.len() > 1 {
        let pivot_index = partition(slice);
        let (left, right) = slice.split_at_mut(pivot_index);
        quick_sort_in_place(left);
        quick_sort_in_place(&mut right[1..]);
    }
}

fn main() {
    let stdin = std::io::stdin();
    let mut lines = stdin.lock().lines();

    let n: usize = lines.next().unwrap().unwrap().parse().unwrap();

    let mut participants: Vec<Participant> = Vec::with_capacity(n);

    for _ in 0..n {
        let line = lines.next().unwrap().unwrap();
        let parts: Vec<&str> = line.split_whitespace().collect();
        let name = parts[0].to_string();
        let value1: i32 = parts[1].parse().unwrap();
        let value2: i32 = parts[2].parse().unwrap();
        participants.push(Participant::new(name, value1, value2));
    }

    quick_sort_in_place(&mut participants);

    let stdout = std::io::stdout();
    let mut stdout = stdout.lock();

    for participant in &participants {
        writeln!(stdout, "{}", participant.login).unwrap();
    }
}