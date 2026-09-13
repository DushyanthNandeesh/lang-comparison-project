fn main() {
    let n = 5_000_000;
    let arr: Vec<i32> = (0..n).collect();
    let sum: i64 = arr.iter().map(|&x| x as i64).sum();
    drop(arr);
    println!("sum={}", sum);
}
