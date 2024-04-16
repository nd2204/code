#pragma once

#include "observer.hpp"
#include "subject.hpp"
#include <unordered_set>

class WeatherData: public Subject {
public:
  void registerObserver(Observer*);
  void removeObserver(Observer*);
  void notifyObservers();
  float getHumidity();
  float getTemperature();
  float getPressure();
  void setMeasurements(float temperature, float humidity, float pressure);
  void measurementsChanged();
private:
  std::unordered_set<Observer*> observers;
  float temperature;
  float humidity;
  float pressure;
};
