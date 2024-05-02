#include "weather/weatherdata.hpp"
#include "weather/displays/displays.hpp"

int main() {
  WeatherData wd;

  // Setting up display
  CurrentConditionDisplay currentConditionDisplay(&wd);
  StatisticDisplay statisticDisplay(&wd);
  ForecastDisplay forecastDisplay(&wd);
  HeatIndexDisplay heatIndexDisplay(&wd);

  // Update the weather data
  wd.setMeasurements(80, 64, 30.4f);
  currentConditionDisplay.display();
  statisticDisplay.display();
  forecastDisplay.display();
  heatIndexDisplay.display();
  wd.setMeasurements(82, 70, 29.2f);
  currentConditionDisplay.display();
  statisticDisplay.display();
  forecastDisplay.display();
  heatIndexDisplay.display();
  wd.setMeasurements(78, 90, 29.2f);
  currentConditionDisplay.display();
  statisticDisplay.display();
  forecastDisplay.display();
  heatIndexDisplay.display();
}
