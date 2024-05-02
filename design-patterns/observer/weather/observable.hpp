#pragma once

#include "observer.hpp"
#include <unordered_set>

class Observable {
public:
  Observable();
  void registerObserver(Observer* o);
  void removeObserver(Observer* o);
  void notifyObservers();
  void setChanged();
protected:
  std::unordered_set<Observer*> observers;
  bool changed;
};
