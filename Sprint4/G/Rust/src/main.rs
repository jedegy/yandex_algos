// https://contest.yandex.ru/contest/23991/problems/G/

fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();

    let mut rounds = Vec::new();
    input.clear();
    std::io::stdin().read_line(&mut input).unwrap();
    rounds.extend(input.trim().split_whitespace().map(|s| {
        let num: i32 = s.parse().unwrap();
        if num == 0 {
            -1
        } else {
            num
        }
    }));

    let mut map = std::collections::HashMap::new();
    map.insert(0, -1);
    let mut summ = 0;
    let mut result = 0;

    for i in 0..n as i32 {
        summ += rounds[i as usize];
        if !map.contains_key(&summ) {
            map.insert(summ, i);
        } else {
            result = result.max(i - *map.get(&summ).unwrap());
        }
    }

    println!("{}", result);
}
