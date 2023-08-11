/*
-- WORKING PRINCIPLE --
The solution is based on a modification of the binary search algorithm to work with "broken" sorted arrays.
First, the "pivot" point in the array is determined, then a normal binary search is used, taking into account this point.

-- PROOF OF CORRECTNESS --
The `search_pivot` function correctly finds the pivot point index in a broken array using the properties of the sorted array.
The `search_in_broken_array` function correctly performs a binary search, given offset due to rotation.

The methods correctly handle edge cases, such as finding elements that are before and after the rotation.

-- TIME COMPLEXITY --
The time complexity of pivot and binary search in a broken array is O(log n), where n is the size of the array.

-- SPACE COMPLEXITY --
Since only a few additional variables are used to store indexes and there are no additional data structures, the space complexity is O(1).
*/

/// Finds the pivot of rotation in a broken array.
///
/// The pivot of rotation is the index of the largest element.
///
/// # Arguments
///
/// * `vec` - A reference to the broken array.
///
/// # Returns
///
/// Index of the largest element (pivot).
fn search_pivot(vec: &[i32]) -> usize {
    let mut left = 0;
    let mut right = vec.len() - 1;

    while left < right {
        let middle = left + (right - left) / 2;
        if vec[middle] > vec[right] {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    left
}

/// Performs a binary search on a broken array.
///
/// # Arguments
///
/// * `vec` - A reference to the broken array.
/// * `k` - The target element to search for.
///
/// # Returns
///
/// If the element is found, returns its index; otherwise returns -1.
pub fn broken_search(vec: &[i32], k: i32) -> i32 {
    let mut left = 0i32;
    let mut right = (vec.len() - 1) as i32;
    let pivot = search_pivot(vec);

    // Directly compare with the pivot value first
    if vec[pivot] == k {
        return pivot as i32;
    }

    // If the first element of the array is less than the target, then look in the first half (before the pivot).
    // Otherwise, look in the second half (after the pivot).
    if vec[0] <= k {
        // Array already sorted?
        if pivot == 0 {
            right = (vec.len() - 1) as i32;
        } else {
            right = (pivot - 1) as i32;
        }
    } else {
        left = pivot as i32;
    }

    while left <= right {
        let middle = left + (right - left) / 2;
        if vec[middle as usize] == k {
            return middle;
        } else if vec[middle as usize] < k {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    -1
}

#[cfg(test)]
mod tests {
    use super::broken_search;
    #[test]
    fn test_1() {
        let arr = [19, 21, 100, 101, 1, 4, 5, 7, 12];
        assert_eq!(6, broken_search(&arr, 5));
    }

    #[test]
    fn test_2() {
        let arr = [5, 1];
        assert_eq!(1, broken_search(&arr, 1));
    }

    #[test]
    fn test_array_with_one_elem() {
        let arr = [5];
        assert_eq!(0, broken_search(&arr, 5));
    }

    #[test]
    fn negative_test() {
        let arr = [5];
        assert_eq!(-1, broken_search(&arr, 1));
    }

    #[test]
    fn test_10() {
        let arr = [1, 2, 3, 5, 6, 7, 9, 0];
        assert_eq!(2, broken_search(&arr, 3));
    }

    #[test]
    fn test_sorted_array() {
        let arr = [12, 41, 122, 411, 412, 1222, 3000, 12222, 122222];
        assert_eq!(6, broken_search(&arr, 3000));
    }
}