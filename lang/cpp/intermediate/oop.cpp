#include <iostream>
using namespace std;

class Car {                 // Class name
public:                     // Public access specifier 

    int year;               // Public Attribute (int) variable
    string brand;           // Public Atrribute (string) variable
    string model;           // Public Atrribute (string) variable

    void getInfo();         // Public Methods (function) declaration

    // Constructor (with parameter)
    Car(int _year, string _brand, string _model);   // Declare constructor 
}; // semi-colon is required

// Constructor definition outside the class
Car::Car(int _year, string _brand, string _model) {
    year = _year;
    brand = _brand;
    model = _model;
}

// Define function/method outside the class
void Car::getInfo() {
    cout << "This is " << year << " " << brand.append(" ")  << model << endl;
}

int main() {
    Car tesla(2023, "tesla", "Model X");    // Call the constructor with diferent values

    cout << tesla.year << endl;
    cout << tesla.brand << endl;
    cout << tesla.model << endl;

    // Access and modify the object variable
    tesla.year = 2021;
    tesla.model = "Model 3";

    // Call the method of the object
    tesla.getInfo();

    return 0;
}
