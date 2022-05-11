#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"

#define private public
#include "Receiver.h"

using namespace std;

typedef ::std::map< int , Sensors> T_SensorNameMap;
T_SensorNameMap m_sensorNameMap;
void prepareSensorMap()
{
 m_sensorNameMap[0] = UNKNOWN;
 m_sensorNameMap[1] = CURRENT;
 m_sensorNameMap[2] = TEMPERATURE;
}

Sensors getSensorName(int value)
{
 Sensors sensor = UNKNOWN;
 T_SensorNameMap::const_iterator sensorNameMapIt = m_sensorNameMap.find(value);
 if(sensorNameMapIt != m_sensorNameMap.end())
 {
  sensor = sensorNameMapIt->second;
 }
 return sensor;
}

TEST_CASE("check_for_Receive_And_Compute_Sensor_data")
{
 T_SensorDataMap sensorDataMap = receiveAndComputeTheSensorData(&readAndStoreTheDataFromConsole,
                                                                &calculateSMAforLastFewValues, 
                                                                &findMaxAndMinValuesForGivenSensor, 
                                                                &printDataForGivenSensor);
  REQUIRE(sensorDataMap.size() == 2);
  for(unsigned int i = 0; i < sensorDataMap.size(); ++i)
  {
   Sensors sensor = getSensorName(i);
    SensorData sensorData = sensorDataMap[sensor];
   if(i != 0)
   {
       REQUIRE(sensorData.smaValue != 0.0);
   }
  }
}

TEST_CASE("check_for_calculate_SMA_value_for_given_Sensor_Readings")
{
  ::std::vector<int> sensorReadings = {1,8,5,6,8,5,2,8,7,4,16,58,74,23,6,8,52,2,1,5,2,65,8};
  float expectedSmaValue = 16.2;
  float actualSmaValue = calculateSMAforLastFewValues(sensorReadings);
  REQUIRE(actualSmaValue == expectedSmaValue);
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
  T_SensorValuesMap sensorValuesMap;
 sensorValuesMap = readAndStoreTheDataFromConsole();
  REQUIRE(sensorValuesMap.size() == 2);
  for(unsigned i = 0; i < sensorValuesMap.size(); ++i)
  {
   Sensors sensor = getSensorName(i);
    ::std::vector<int> sensorReadings = sensorValuesMap[sensor];
   if(i!=0)
   {
        REQUIRE(sensorReadings.size() == 50);
   }
  }
}
