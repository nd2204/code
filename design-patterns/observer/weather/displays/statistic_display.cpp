#include "statistic_display.hpp"
#include <iostream>

StatisticDisplay::StatisticDisplay(WeatherData* wd) {
  if (wd) {
    this->weatherData = wd;
    weatherData->registerObserver(this);
    maxTemp = -200;
    minTemp = 200;
    numReadings = 0;
    tempSum = 0;
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
    << tempSum/numReadings << '/' << maxTemp << '/' << minTemp << "\n";
}
