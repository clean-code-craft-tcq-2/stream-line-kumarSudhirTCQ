// Online C++ compiler to run C++ program online
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <array>
#include <random>

using namespace std;

typedef ::std::map<::string, ::vector<int>> T_SensorValues;
typedef ::std::map<::string,::std::vector< float>> T_SMAValues;
T_SensorValues m_sensorValues; 
T_SMAValues m_smaValues;

void readTheDataFromConsole()
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
  for(int j= 0; j<ampValues.size();j++)
  {
::cout<<ampValues[j]<<endl;
  }
    for(int k= 0; k<tempValues.size();k++)
  {
::cout<<tempValues[k]<<endl;
  }


}
