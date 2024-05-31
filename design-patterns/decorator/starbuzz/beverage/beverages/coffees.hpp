#pragma once

#include "../beverage.hpp"

namespace zu4 {
  class HouseBlend : public Beverage {
  public:
    HouseBlend();
    double cost();
    ~HouseBlend();
  };

  class DarkRoast : public Beverage {
  public:
    static int i;
    DarkRoast();
    template<typename T>
    T cost();
    virtual void update() = 0;
  };
  void update();
}

namespace dn200 {
  template<typename T, class U, class V = int>
  class HouseBlend : public Beverage {
  public:
    HouseBlend();
    T cost();
    ~HouseBlend();
  };

  class DarkRoast : public Beverage {
  public:
    DarkRoast();
    template<typename , class U, class V = int>
    T cost();
    virtual void update() = 0;
    bool operator>(DarkRoast& rhs);
    friend bool operator>(DarkRoast& lhs, DarkRoast& rhs);
  };
  void update();
}

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

int i = 0;
static void update();

Expresso new();
