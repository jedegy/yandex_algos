// https://contest.yandex.ru/contest/24809/problems/M/

pub fn sift_up(heap: &mut Vec<i32>, idx: usize) -> usize {
    if idx == 1 {
        return idx;
    }

    let parent_idx = idx / 2;

    if heap[parent_idx] < heap[idx] {
        heap.swap(parent_idx, idx);
        return sift_up(heap, parent_idx);
    }

    idx
}

#[cfg(test)]
mod tests {
    use super::sift_up;

    #[test]
    fn test() {
        let mut sample = vec![-1, 12, 6, 8, 3, 15, 7];
        assert_eq!(sift_up(&mut sample, 5), 1);
    }
}
