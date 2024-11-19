#include "beverage.hpp"
#include <iostream>

Beverage::Beverage() {
  description = "Unknown Beverage";
  std::cout << "Base class Beverage called\n";
}

std::string Beverage::getDescription() {
  return description;
}
