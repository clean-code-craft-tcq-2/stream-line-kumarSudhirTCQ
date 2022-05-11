#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"

#define private public
#include "Receiver.h"

using namespace std;

TEST_CASE("check_for_Receive_And_Compute_Sensor_data")
{
 T_SensorDataMap sensorDataMap = receiveAndComputeTheSensorData(&readAndStoreTheDataFromConsole,
                                                                &calculateSMAforLastFewValues, 
                                                                &calculateMaxAndMinValuesForGivenSensor, 
                                                                &printDataForGivenSensor);
  REQUIRE(sensorDataMap.size() == 2);
  for(unisigned int i = 0; i < sensorDataMap.size(); ++i)
  {
    SensorData sensorData = sensorDataMap[i];
    REQUIRE(sensorData.smaValue != 0.0);
  }
}

TEST_CASE("check_for_calculate_SMA_value_for_given_Sensor_Readings")
{
  ::std::vector<int> sensorReadings = {1,8,5,6,8,5,2,8,7,4,16,58,74,23,6,8,52,2,1,5,2,65,8};
  float expectedSmaValue = 16.2;
  float actualSmaValue = calculateSMAforLastFewValues(sensorReadings);
  REQUIRE(actualSmaValue == expectedSmaValue)
}

TEST_CASE("check_for_find_Max_Min_values_For_given_Readings")
{
  MaxAndMinValues actualMinMaxValue;
  ::std::vector<int> sensorReadings = {1,8,5,6,8,5,2,8,7,4,16,58,74,23,6,8,52,2,1,5,2,65,8};
  int expectedMaxValue = 74;
  int expectedMinValue = 1;
  actualMinMaxValue = findMaxAndMinValuesForGivenSensor(sensorReadings);
  REQUIRE(actualMinMaxValue.minValue == expectedMinValue);
  REQUIRE(actualMinMaxValue.maxValue == expectedMaxValue);
}

TEST_CASE("check_for_read_data_from_console_And_store_the_Data")
{
  T_SensorValues sensorValuesMap;
  readAndStoreTheDataFromConsole(sensorValuesMap);
  REQUIRE(sensorValuesMap.size() == 2)
  for(unsigned int i = 0; i < sensorValuesMap.size(); ++i)
  {
    ::std::vector<int> sensorReadings = sensorValuesMap[i];
    REQUIRE(sensorReadings.size() == 50)
  }
}
