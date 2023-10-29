// https://contest.yandex.ru/contest/26131/problems/I/

fn prefix_function(s: &str) -> Vec<usize> {
    let bytes = s.as_bytes();
    let mut prefix = vec![0; s.len()];

    for i in 1..s.len() {
        let mut k = prefix[i - 1];
        while k > 0 && bytes[k] != bytes[i] {
            k = prefix[k - 1];
        }
        if bytes[k] == bytes[i] {
            k += 1;
        }

        prefix[i] = k;
    }

    prefix
}

fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let s = s.trim();

    let prefix = prefix_function(&s);

    let last_prefix_value = prefix[s.len() - 1];
    if last_prefix_value >= s.len() / 2 {
        println!("{}", s.len() / (s.len() - last_prefix_value));
    } else {
        println!("1");
    }
}
