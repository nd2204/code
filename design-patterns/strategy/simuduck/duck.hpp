#pragma once

#include "quack_behavior.hpp"
#include "fly_behavior.hpp"

class Duck {
public:
    void performQuack();
    void performFly();
    virtual void display() = 0;
protected:
    QuackBehaviour *quackBehaviour;
    FlyBehaviour *flyBehaviour;
};
