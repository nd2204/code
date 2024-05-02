#pragma once

class QuackBehaviour {
public:
    virtual void quack() = 0;
    virtual ~QuackBehaviour() {};
};

class Quack : public QuackBehaviour {
public:
    void quack();
};

class Squeak : public QuackBehaviour {
public:
    void quack();
};

class MuteQuack : public QuackBehaviour {
public:
    void quack();
};
