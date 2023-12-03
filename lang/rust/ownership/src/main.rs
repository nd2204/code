fn main() {
    let first = String::from("Ferris");

    // Without clone (This will not compile)
    {
        // let full = add_suffix(first);
        // println!("{full}, original: {first}");
    }

    // With clone
    {
        let full = add_suffix(first.clone());
        println!("{full}, original: {first}");
    }
}

fn add_suffix(mut name: String) -> String {
    name.push_str(" Jr.");
    return name
}
