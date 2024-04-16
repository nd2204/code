#include "forecast_display.hpp"
#include <iostream>

ForecastDisplay::ForecastDisplay(WeatherData* wd) {
  if (wd) {
    this->weatherData = wd;
    weatherData->registerObserver(this);
    lastPressure = currentPressure = weatherData->getPressure();
  }
}

void ForecastDisplay::update(float temperature, float humidity, float pressure) {
  lastPressure = currentPressure;
  currentPressure = pressure;
}

void ForecastDisplay::display() {
  if (currentPressure > lastPressure) {
    std::cout << "Improving weather on the way!\n";
  }
  else if (currentPressure < lastPressure) {
    std::cout << "Watch out for cooler, rainy weather\n";
  }
  else {
    std::cout << "More of the same\n";
  }
}
