// Online C++ compiler to run C++ program online
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <random>

using namespace std;

typedef ::std::map<::string, ::vector<int>> T_SensorValues;
typedef ::std::map<::string,::std::vector< float>> T_SMAValues;
T_SensorValues m_sensorValues; 
T_SMAValues m_smaValues;

::std::vector< int> generateValues()
{
  ::std::vector< int> readings;
  std::random_device rd; // obtain a random number from hardware
  std::mt19937 gen(rd()); // seed the generator
  std::uniform_int_distribution<> distr(0, 100); // define the range
  for(int n=0; n<50; ++n)
  {
    readings.push_back(distr(gen));
  }
  return readings;
}
void fillSensorValuesMap(T_SensorValues& sensorValues)
{
    if(sensorValues.empty())
    {
        sensorValues["Amps"] = generateValues();
        sensorValues["Temp"] = generateValues();
    }
}

::std::vector< float> calucateSMA(::vector<int> sensorValues)
{
    ::std::vector< float> smaValuesList;
    float sum = 0.0;
    for(int i = 0 ; i < sensorValues.size(); ++i)
    {
        sum += sensorValues[i];
        float average = sum/(i+1);
        smaValuesList.push_back(average);
    }
    return smaValuesList;
}

void processSMA()
{
    ::std::map<::string, ::vector<int>>::const_iterator sensoraluesIt = m_sensorValues.begin();
    for(; sensoraluesIt != m_sensorValues.end(); ++sensoraluesIt)
    {
        m_smaValues[sensoraluesIt->first] = calucateSMA(sensoraluesIt->second);
    }
}
