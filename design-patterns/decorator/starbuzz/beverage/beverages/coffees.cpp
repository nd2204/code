#include "coffees.hpp"
#include <iostream>

Espresso::Espresso() {
  description = "Espresso";
  std::cout << "Derived class Espresso called\n";
}

double Espresso::cost() {
  return 1.99;
}

HouseBlend::HouseBlend() {
  description = "House Blend Coffee";
  std::cout << "Derived class HouseBlend called\n";
}

double HouseBlend::cost() {
  return 0.89;
}

DarkRoast::DarkRoast() {
  description = "Dark Roast";
  std::cout << "Derived class DarkRoast called\n";
}

double DarkRoast::cost() {
  return 0.99;
}

Decaf::Decaf() {
  description = "Decaf";
  std::cout << "Derived class Decaf called\n";
}

double Decaf::cost() {
  return 1.05;
}

