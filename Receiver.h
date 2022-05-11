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

void readTheDataFromConsole()
{
  ::std::string dataFromConsole;
  scanf("%s", dataFromConsole);
  ::cout<<dataFromConsole<<endl;
}
