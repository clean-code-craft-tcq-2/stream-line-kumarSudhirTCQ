// Online C++ compiler to run C++ program online
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <array>
#include <random>

using namespace std;

typedef enum
{
  CURRENT,
  TEMPERATURE
}Sensors;

 struct MaxAndMinValues
{
     int maxValue;
     int minValue;
} ;

struct SensorData
{
  MaxAndMinValues minMaxValues;
  float smaValue;
};

typedef ::std::map<Sensors, ::vector<int>> T_SensorValuesMap;
typedef ::std::map<Sensors, SensorData> T_SensorDataMap;
typedef void(*readfnPtr)(T_SensorValuesMap);
typedef float(*calcSMA_fnPtr)(::std::vector<int>);
typedef MaxAndMinValues(*calc_minMaxValuePtr)(::std::vector<int>);
typedef void(*print_fnPtr)(Sensors, MaxAndMinValues, float);

void readAndStoreTheDataFromConsole(T_SensorValuesMap& sensorValuesMap)
{
  ::cout<<"Received Data"<<endl;
  ::vector<int> ampValues;
  ::vector<int> tempValues;
  for(int i =0;i<50;++i)
  {
    int amps, temp;
     scanf("%*s%d %*s %*s%d",&amps,&temp);
      ::cout<<"Amps:"<<" "<<amps<<" "<<","<<" "<<"Temp:"<<" "<<temp<<endl;
    ampValues.push_back(amps);
    tempValues.push_back(temp);
  }
 sensorValuesMap[CURRENT] = ampValues;
 sensorValuesMap[TEMPERATURE] = tempValues;
}

MaxAndMinValues findMaxAndMinValuesForGivenSensor(const ::std::vector<int> sensorValues)
{
  MaxAndMinValues maxMinValues;
    maxMinValues.maxValue =  *max_element(sensorValues.begin(), sensorValues.end());
    maxMinValues.minValue =  *min_element(sensorValues.begin(), sensorValues.end());
  return maxMinValues;
}

 float calculateSMAforLastFewValues(const ::std::vector<int> sensorValues)
{
  float sum = 0.0, smaValue = 0.0;
  ::std::vector< float> smaValueList;
  const ::std::vector<int>::const_iterator sensorValuesIt = sensorValues.begin();
  for(unsigned int  i = (sensorValues.size() - 5); i <= sensorValues.size(); ++i)
  {
    sum = sum + sensorValues[i] ;
  }
  smaValue = sum/sensorValues.size();
   ::cout<<"smaValue - "<<smaValue<<" for "<<sensorValues.size()<<" values for the sensor"<< endl;
  return smaValue;
}

void printDataForGivenSensor(Sensors sensorName, MaxAndMinValues minMaxValue, float smaValue)
{
  ::cout<<sensorName<<" - "<<"maxValue : "<<minMaxValue.maxValue<<" "<<"minValue : "<<minMaxValue.minValue<<" "<<"SMA Value : "<<endl;
}

SensorData updateSensorData(MaxAndMinValues minMaxValues, float smaValue)
{
    SensorData sensorData;
    sensorData.minMaxValues = minMaxValues;
    sensorData.smaValue = smaValue;
    return sensorData;
}

T_SensorDataMap receiveAndComputeTheSensorData(void(*readfnPtr)(T_SensorValuesMap),
                                    float(*calcSMA_fnPtr)(::std::vector<int>),
                                    MaxAndMinValues(*calc_minMaxValuePtr)(::std::vector<int>),
                                    void(*print_fnPtr)(Sensors, MaxAndMinValues, float))
{
  T_SensorDataMap sensorDataMap;
  float smaValue = 0.0;
  MaxAndMinValues minMaxvalue;
  T_SensorValuesMap sensorValuesMap;
  fnPtr(sensorValuesMap);
  T_SensorValuesMap::const_iterator sensorValuesMapIt = sensorValuesMap.begin();
  for(;sensorValuesMapIt != sensorValuesMap.end(); ++sensorValuesMapIt)
  {
    smaValue = calcSMA_fnPtr(sensorValuesmapIt->second);
    minMaxvalue = calc_minMaxValuePtr(sensorValuesmapIt->second)
    print_fnPtr( sensorValuesmapIt->first, minMaxvalue, smaValue ));
    sensorDataMap[sensorValuesmapIt->first] = updateSensorData( minMaxvalue, smaValue);
  }
  return sensorDataMap;
}












