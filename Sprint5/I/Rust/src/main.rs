// https://contest.yandex.ru/contest/24809/problems/I/

fn get_num_bin_search_trees(n: usize) -> u64 {
    let mut nums = vec![0; n + 1];
    nums[0] = 1u64;
    nums[1] = 1u64;

    for i in 2..n + 1 {
        for j in 0..i {
            nums[i] += nums[j] * nums[i - j - 1];
        }
    }

    nums[n]
}

fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n = input.trim().parse::<usize>().unwrap();

    println!("{}", get_num_bin_search_trees(n));
}
