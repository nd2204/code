fn main() {
    if_else();
    looping();
}

fn if_else() {
    let number = 7;

    // Usage
    {
        // Condition MUST be a bool
        if number < 5 {
            println!("Condition was true");
        } else {
            println!("Condition was false");
        }
    }

    // Multiple Condition
    {
        if number % 4 == 0 {
            println!("The number is divisible by 4");
        } else if number % 3 == 0 {
            println!("The number is divisible by 3");
        } else if number % 2 == 0 {
            println!("The number is divisible by 2");
        } else {
            println!("The number is not divisible by 4, 3, or 2");
        }
    }

    // Ternary operator
    {
        let condition = true;
        let value = if condition { 5 } else { 6 };
        println!("The value is: {value}");
    }
}

fn looping() {
    // Return value with loop
    {
        let mut counter = 0;

        let result = loop {
            counter += 1;

            if counter == 10 {
                break counter * 2;
            }
        };
        println!("The result is {result}");
    }

    // Loop Labels to Disambiguate Between Multiple Loops
    {
        let mut count = 0;
        'counting_up: loop {
            println!("Count = {count}");
            let mut remaining = 10;

            loop {
                println!("Remaining = {remaining}");
                if remaining == 9 {
                    break;
                }
                if count == 2 {
                    break 'counting_up;
                }
                remaining -= 1;
            }

            count += 1;
        }
    }

    // While loop
    {
        let mut number = 3;

        while number > 0 {
            println!("{number}!");
            number -= 1;
        }
        println!("LIFTOFF!!!");
    }

    // Looping through collection
    {
        let a = [10, 20, 30, 40, 50];

        for elem in a {
            println!("the values is: {elem}");
        }
    }


    // Looping with Range
    {
        for i in (1..10).rev() {
            println!("{i}");
        }
    }
}
