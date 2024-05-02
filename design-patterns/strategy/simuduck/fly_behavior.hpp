#pragma once

class FlyBehaviour {
public:
    virtual void fly() = 0;
};

class FlyWithWings : public FlyBehaviour {
public:
    void fly();
};

class FlyNoWay : public FlyBehaviour {
public:
    void fly();
};
