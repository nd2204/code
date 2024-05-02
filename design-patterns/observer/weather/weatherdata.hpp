#pragma once

#include "observer.hpp"
#include "observable.hpp"
#include <unordered_set>

class WeatherData: public Observable {
public:
  WeatherData();
  void registerObserver(Observer*);
  void removeObserver(Observer*);
  void notifyObservers();
  float getHumidity();
  float getTemperature();
  float getPressure();
  void setMeasurements(float temperature, float humidity, float pressure);
  void measurementsChanged();
private:
  float temperature;
  float humidity;
  float pressure;
};
