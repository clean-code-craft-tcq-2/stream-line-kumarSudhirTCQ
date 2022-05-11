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
  char dataAmps[5],dataTemp[7],separator[1];
  int amps,temps;
  char data[5];
  for(int i =0;i<50;++i)
  {
     scanf("%*s%d %*s %*s%d",&amps,&temps);
      ::cout<<"Amps:"<<" "<<amps<<" "<<","<<" "<<"Temp:"<<" "<<temps<<endl;
  }
// scanf("%*s%d %*s %*s%d",&amps,&temps);
//   cout<<data<<endl;
}
