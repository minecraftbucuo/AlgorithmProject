// 1. https://atcoder.jp/contests/abc450/tasks/abc450_a
// use std::io;
//
// fn main() {
//     let mut input : String = String::new();
//     io::stdin().read_line(&mut input).unwrap();
//     let n : i32 = input.trim().parse::<i32>().unwrap();
//     let ans : Vec<String> = (1..=n).rev().map(|x| x.to_string()).collect();
//     println!("{}", ans.join(","))
// }

// 2. https://atcoder.jp/contests/abc450/tasks/abc450_b
use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n = input.trim().parse::<usize>().unwrap();

    let mut ve = vec![vec![0i32; n + 1]; n + 1];

    for i in 1..n {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let mut it = input.split_whitespace().map(|x| x.parse::<i32>().unwrap());
        for j in (i + 1)..=n {
            ve[i][j] = it.next().unwrap();
        }
    }

    let mut found = false;

    for a in 1..=n {
        for b in (a + 1)..=n {
            for c in (b + 1)..=n {
                if ve[a][b] + ve[b][c] < ve[a][c] {
                    found = true;
                    break;
                }
            }
            if found {
                break;
            }
        }
        if found {
            break;
        }
    }

    if found {
        println!("Yes");
    } else {
        println!("No");
    }
}