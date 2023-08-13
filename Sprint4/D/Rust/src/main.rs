// https://contest.yandex.ru/contest/23991/problems/D/
fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();

    let mut map: std::collections::HashMap<String, i32> = std::collections::HashMap::new();
    let mut names = Vec::new();

    for _ in 0..n {
        input.clear();
        std::io::stdin().read_line(&mut input).unwrap();
        let name = input.trim().to_string();
        *map.entry(name.clone()).or_insert(0) += 1;
        names.push(name);
    }

    for name in &names {
        if let Some(value) = map.get_mut(name) {
            if *value > 0 {
                println!("{}", name);
                *value = 0;
            }
        }
    }
}
