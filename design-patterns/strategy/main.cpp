#include <iostream>

#include "simuduck/duck.hpp"

class MallardDuck : public Duck {
public:
    void display() {
        std::cout << "I'm a real mallard duck\n";
    }

    MallardDuck() {
        quackBehaviour = new Quack();
        flyBehaviour = new FlyWithWings();
    }
};

int main(void)
{
    Duck *mallard = new MallardDuck();
    mallard->performQuack();
    mallard->performFly();
    mallard->display();
}
