#include "beverage.hpp"
#include <iostream>

Beverage::Beverage() {
  description = "Unknown Beverage";
}

std::string Beverage::getDescription() {
  return description;
}
