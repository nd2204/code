#pragma once

#include "../beverage.hpp"

class Espresso : public Beverage {
public:
  Espresso();
  double cost() override;
};

class HouseBlend : public Beverage {
public:
  HouseBlend();
  double cost() override;
};

class DarkRoast : public Beverage {
public:
  DarkRoast();
  double cost() override;
};

class Decaf : public Beverage {
public:
  Decaf();
  double cost() override;
};
