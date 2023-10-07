// https://contest.yandex.ru/contest/25596/problems/C/

struct Bunch {
    price: usize,
    kilo: usize,
}

fn main() {
    let mut lines = std::io::stdin().lines();
    let mut m = lines.next().unwrap().unwrap().parse::<usize>().unwrap();
    let n = lines.next().unwrap().unwrap().parse::<usize>().unwrap();

    let mut bunches = Vec::with_capacity(n);

    for _ in 0..n {
        let bunch = lines
            .next()
            .unwrap()
            .unwrap()
            .split_whitespace()
            .map(|x| x.parse::<usize>().unwrap())
            .collect::<Vec<usize>>();
        bunches.push(Bunch {
            price: bunch[0],
            kilo: bunch[1],
        });
    }

    bunches.sort_unstable_by(|a, b| {
        if a.price == b.price {
            a.kilo.cmp(&b.kilo)
        } else {
            b.price.cmp(&a.price)
        }
    });

    let mut max_summ = 0;

    for bunch in bunches {
        if m as i64 - bunch.kilo as i64 >= 0 {
            max_summ += bunch.kilo * bunch.price;
            m -= bunch.kilo;
        } else {
            max_summ += m * bunch.price;
            break;
        }
    }

    println!("{}", max_summ);
}
