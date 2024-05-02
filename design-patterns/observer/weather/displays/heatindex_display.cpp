#include "heatindex_display.hpp"
#include <iostream>
#include <math.h>

HeatIndexDisplay::HeatIndexDisplay(WeatherData* wd) {
  if (wd) {
    this->weatherData = wd;
    weatherData->registerObserver(this);
    heatindex = 0.0f;
  }
}

void HeatIndexDisplay::update(float temperature, float humidity, float pressure) {
  const float T = temperature;
  const float RH = humidity;
  heatindex = 16.923 + 1.85212 * pow(10, -1) * T + 5.37941 * RH - 1.00254 * pow(10, -1) *
    T * RH + 9.41695 * pow(10, -3) * pow(T, 2) + 7.28898 * pow(10,-3) * pow(RH,2) + 3.45372 *
    pow(10, -4) * pow(T, 2) * RH - 8.14971 * pow(10, -4) * T * pow(RH, 2) + 1.02102 * pow(10, -5) * pow(T, 2) *
    pow(RH, 2) - 3.8646 * pow(10, -5) * pow(T, 3) + 2.91583 * pow(10, -5) * pow(RH, 3) + 1.42721 * pow(10, -6)
    * pow(T, 3) * RH + 1.97483 * pow(10, -7) * T * pow(RH, 3) - 2.18429 * pow(10, -8) * pow(T, 3) * pow(RH, 2)
    + 8.43296 * pow(10, -10) * pow(T, 2) * pow(RH, 3) - 4.81975 * pow(10, -11) * pow(T, 3) * pow(RH, 3);
}

void HeatIndexDisplay::display() {
  std::cout << "Heat Index: " << heatindex << '\n';
}
