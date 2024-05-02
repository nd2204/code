#include "quack_behavior.hpp"
#include <iostream>

void Quack::quack() { std::cout << "QUACK!\n"; }
void Squeak::quack() { std::cout << "Squeak!\n"; }
void MuteQuack::quack() { std::cout << "<< Silence >>\n"; }
