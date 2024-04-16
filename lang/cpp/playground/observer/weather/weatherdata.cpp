#include "weatherdata.hpp"

void WeatherData::registerObserver(Observer* o) { observers.insert(o); }
void WeatherData::removeObserver(Observer* o) { observers.erase(o); }

void WeatherData::notifyObservers() {
  for (auto observer: observers) {
    observer->update(temperature, humidity, pressure);
  }
}

float WeatherData::getTemperature() { return temperature; }
float WeatherData::getHumidity() { return humidity; }
float WeatherData::getPressure() { return pressure; }
void WeatherData::measurementsChanged() { notifyObservers(); }

void WeatherData::setMeasurements(float temperature, float humidity, float pressure) {
  this->temperature = temperature;
  this->humidity = humidity;
  this->pressure = pressure;
  measurementsChanged();
}
