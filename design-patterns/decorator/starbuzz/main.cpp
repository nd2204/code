#include "iostream"
#include "beverage/beverages/coffees.hpp"
#include "beverage/condiments/condiments.hpp"

int main() {
  Beverage* beverage = new Espresso();
  std::cout << beverage->getDescription() << " $" << beverage->cost() << '\n';

  Beverage* beverage2 = new DarkRoast();
  beverage2 = new Mocha(beverage2);
  beverage2 = new Mocha(beverage2);
  beverage2 = new Whip(beverage2);
  std::cout << beverage2->getDescription() << " $" << beverage2->cost() << '\n';

  Beverage* beverage3 = new HouseBlend();
  beverage3 = new Mocha(beverage3);
  beverage3 = new Mocha(beverage3);
  beverage3 = new Whip(beverage3);
  std::cout << beverage3->getDescription() << " $" << beverage3->cost() << '\n';

  return 0;
}
