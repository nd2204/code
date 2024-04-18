#pragma once

#include <string>

class Beverage {
public:
  Beverage();
  std::string getDescription();
  virtual double cost() = 0;
protected:
  std::string description;
};
