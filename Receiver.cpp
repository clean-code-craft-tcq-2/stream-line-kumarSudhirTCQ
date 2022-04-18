// Online C++ compiler to run C++ program online
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <random>
#include "matplotlibcpp.h"

using namespace std;
namespace plt = matplotlibcpp;

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
        ::cout<<"sensorValues["<<i<<"] - "<<sensorValues[i]<<" "<<"sum(before) - "<<sum<<" ";
        sum += sensorValues[i];
        float average = sum/(i+1);
        ::cout<<"sum(after) - "<<sum<<" "<<"average - "<<average<<endl;
        smaValuesList.push_back(average);
    }
    ::cout<<"smaValuesList size - "<<smaValuesList.size()<<endl;
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

void printSenorValues()
{
    ::std::map<::string, ::vector<int>>::const_iterator sensoraluesIt = m_sensorValues.begin();
    for(;sensoraluesIt != m_sensorValues.end(); ++sensoraluesIt)
    {
        ::cout<<sensoraluesIt->first<<" ";
        ::vector<int> readings = sensoraluesIt->second;
        ::cout<<readings.size()<<endl;
        for(int i = 0; i<readings.size(); ++i)
        {
            ::cout<<readings[i]<<" ";
        }
        ::cout<<endl;
    }
}

void printSMAValues(::std::vector< float> smaValuesList)
{
    for(int i = 0; i<smaValuesList.size(); ++i)
    {
        ::cout<<smaValuesList[i]<<" ";
    }
}

int main() 
{
    // Write C++ code here
    fillSensorValuesMap(m_sensorValues);
    printSenorValues();
    processSMA();
    T_SMAValues::iterator smaValuesIt = m_smaValues.begin();
    for(;smaValuesIt != m_smaValues.end(); ++smaValuesIt)
    {
        ::cout<<smaValuesIt->first<<endl;
        printSMAValues(smaValuesIt->second);
        ::cout<<endl;
    }
    return 0;
}
