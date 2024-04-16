#include "current_condition_display.hpp"
#include "iostream"

CurrentConditionDisplay::CurrentConditionDisplay(WeatherData* wd) {
  if (wd) {
    this->weatherData = wd;
    weatherData->registerObserver(this);
  }
}

void CurrentConditionDisplay::display() {
  std::cout << "Current temperature is: " << temperature << "F degrees and "
    << humidity << "% humidity\n";
}

void CurrentConditionDisplay::update(float temperature, float humidity, float pressure) {
  this->temperature = temperature;
  this->humidity = humidity;
}
