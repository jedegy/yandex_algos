// https://contest.yandex.ru/contest/25596/problems/D/

fn main() {
    let mut lines = std::io::stdin().lines();
    let n = lines.next().unwrap().unwrap().parse::<usize>().unwrap();

    if n == 0 {
        println!("0");
        return;
    }

    let mut fibonacci = Vec::with_capacity(n + 1);
    fibonacci.push(1i64);
    fibonacci.push(1i64);

    for i in 2..n + 1 {
        fibonacci.push((fibonacci.get(i - 1).unwrap() + fibonacci.get(i - 2).unwrap()) % i64::MAX);
    }

    println!("{}", fibonacci[n]);
}
