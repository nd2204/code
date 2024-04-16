#pragma once

#include "weatherdata.hpp"
#include "display_element.hpp"

class StatisticDisplay : public Observer, public DisplayElement {
public:
  StatisticDisplay(WeatherData*);
  void update(float temperature, float humidity, float pressure);
  void display();
private:
  float maxTemp;
  float minTemp;
  float tempSum;
  int numReadings;
  WeatherData* weatherData;
};
