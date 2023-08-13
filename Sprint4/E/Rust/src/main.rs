// https://contest.yandex.ru/contest/23991/problems/E/

fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let s = s.trim();

    let mut set: std::collections::HashSet<char> = std::collections::HashSet::new();
    let mut result = 0;
    let mut left = 0;
    let mut right = 0;

    while right < s.len() {
        let ch = s.chars().nth(right).unwrap();
        if !set.contains(&ch) {
            set.insert(ch);
            result = std::cmp::max(result, right - left + 1);
            right += 1;
        } else {
            set.remove(&s.chars().nth(left).unwrap());
            left += 1;
        }
    }

    println!("{}", result);
}
