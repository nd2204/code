#include "observable.hpp"

Observable::Observable() {
  changed = false;
}

void Observable::registerObserver(Observer* o) {
  observers.insert(o);
}

void Observable::removeObserver(Observer* o) {
  observers.erase(o);
}

void Observable::notifyObservers() {
  for (auto observer : observers) {
    observer->update();
  }
}

void Observable::setChanged() {
  changed = true;
}
