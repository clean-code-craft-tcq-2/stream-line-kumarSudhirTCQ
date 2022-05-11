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
  ::cout<<"Received Data"<<endl;
  int amps[50];
  int temps[50];
  for(int i =0;i<50;++i)
  {
     scanf("%*s%d %*s %*s%d",&amps[i],&temps[i]);
      ::cout<<"Amps:"<<" "<<amps[i]<<" "<<","<<" "<<"Temp:"<<" "<<temps[i]<<endl;
  }
  for(int j= 0; j<amps.size();j++)
  {
::cout<<amps[j]<<endl;
  }
    for(int k= 0; k<temps.size();k++)
  {
::cout<<temps[k]<<endl;
  }


}
