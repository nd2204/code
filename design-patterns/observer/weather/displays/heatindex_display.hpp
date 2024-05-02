#pragma once

#include "../weatherdata.hpp"
#include "display_element.hpp"

class HeatIndexDisplay : public Observer, public DisplayElement {
public:
  HeatIndexDisplay(WeatherData*);
  void update(float temperature, float humidity, float pressure);
  void display();
private:
  double heatindex;
  WeatherData *weatherData;
};
