
fn main() {
    let mut temp;

    {
        temp = 0;
        println!("F\tC");

        while temp <= 100 {
            let celsius = (temp - 32) * 5 / 9;
            println!("{temp}\t{celsius}");
            temp += 10;
        }
    }

    println!();

    {
        temp = 0;
        println!("C\tF");

        while temp <= 100 {
            let fahrenheit = temp * 9 / 5 + 32;
            println!("{temp}\t{fahrenheit}");
            temp += 10;
        }
    }
}
