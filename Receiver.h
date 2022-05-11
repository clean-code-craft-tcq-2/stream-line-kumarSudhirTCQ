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
  char dataAmps[6],dataTemp[7],separator[1];
  int amps,temps;
  for(int i =0;i<50;++i)
  {
      scanf("%s %d %s %s %d", dataAmps,&amps,separator,dataTemp,&temps);
      ::cout<<dataAmps<<" "<<amps<<" "<<separator<<" "<<dataTemp<<" "<<temps<<endl;
  }

}
