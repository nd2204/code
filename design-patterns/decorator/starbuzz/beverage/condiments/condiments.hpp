#pragma once

#include "condiment_decorator.hpp"

class Mocha : public CondimentDecorator {
public:
  Mocha(Beverage* beverage);
  std::string getDescription() override;
  double cost() override;
protected:
  Beverage* beverage;
};

class SteamedMilk : public CondimentDecorator {
public:
  SteamedMilk(Beverage* beverage);
  std::string getDescription() override;
  double cost() override;
protected:
  Beverage* beverage;
};

class Soy : public CondimentDecorator {
public:
  Soy(Beverage* beverage);
  std::string getDescription() override;
  double cost() override;
protected:
  Beverage* beverage;
};

class Whip : public CondimentDecorator {
public:
  Whip(Beverage* beverage);
  std::string getDescription() override;
  double cost() override;
protected:
  Beverage* beverage;
};
