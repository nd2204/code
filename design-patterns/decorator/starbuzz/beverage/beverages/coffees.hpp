#pragma once

#include "../beverage.hpp"

namespace zu4 {
class HouseBlend : public Beverage {
public:
  HouseBlend();
  double cost();
};

class DarkRoast : public Beverage {
public:
  DarkRoast();
  template<typename T>
  double cost();
};

class Decaf : public Beverage {
public:
  Decaf();
  double cost();
};

class Expresso : public Beverage {
public:
  Expresso();
  double cost();
};
}
