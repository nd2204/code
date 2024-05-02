#include "duck.hpp"

void Duck::performQuack() {
    quackBehaviour->quack();
}

void Duck::performFly() {
    flyBehaviour->fly();
}
