// https://contest.yandex.ru/contest/24809/problems/L/

pub fn sift_down(heap: &mut Vec<i32>, idx: usize) -> usize {
    let left = 2 * idx;
    let right = 2 * idx + 1;

    if left >= heap.len() {
        return idx;
    }

    let mut idx_max = left;
    if right < heap.len() && heap[left] < heap[right] {
        idx_max = right;
    }

    if heap[idx] < heap[idx_max] {
        heap.swap(idx, idx_max);
        return sift_down(heap, idx_max);
    }

    idx
}

#[cfg(test)]
mod tests {
    use super::sift_down;

    #[test]
    fn test() {
        let mut sample = vec![-1, 12, 1, 8, 3, 4, 7];
        assert_eq!(sift_down(&mut sample, 2), 5);
    }
}
