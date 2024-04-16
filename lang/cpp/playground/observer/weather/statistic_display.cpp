#include "statistic_display.hpp"
#include <iostream>

StatisticDisplay::StatisticDisplay(WeatherData* wd) {
  if (wd) {
    this->weatherData = wd;
    weatherData->registerObserver(this);
    maxTemp = minTemp = weatherData->getTemperature();
    numReadings = 0;
  }
}

void StatisticDisplay::update(float temperature, float humidity, float pressure) {
  tempSum += temperature;
  if (temperature > maxTemp) maxTemp = temperature;
  if (temperature < minTemp) minTemp = temperature;
  numReadings++;
}

void StatisticDisplay::display() {
  std::cout << "AVG/MAX/MIN temperature = "
    << tempSum/numReadings << '/' << maxTemp << '\n' << minTemp << "\n";
}
