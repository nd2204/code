#pragma once

#include "../observer.hpp"
#include "../weatherdata.hpp"
#include "display_element.hpp"

class CurrentConditionDisplay : public Observer, DisplayElement {
public:
  CurrentConditionDisplay(WeatherData*);
  void display();
  void update(float temperature, float humidity, float pressure);
private:
  float temperature;
  float humidity;
  WeatherData* weatherData;  
};
