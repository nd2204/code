#pragma once

#include "../weatherdata.hpp"
#include "display_element.hpp"

class ForecastDisplay : public Observer, public DisplayElement {
public:
  ForecastDisplay(WeatherData*); 
  void update(float temperature, float humidity, float pressure);
  void display();
private:
  float currentPressure;
  float lastPressure;
  WeatherData* weatherData;
};
