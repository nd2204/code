#pragma once

#include "../beverage.hpp"
#include <string>

class CondimentDecorator : public Beverage {
public:
  virtual std::string getDescription() = 0;
private:
};
