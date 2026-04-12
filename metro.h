#ifndef METRO_H
#define METRO_H
#include<string>
#include<map>
using namespace std;
class DelhiMetro{
    int V;
    map<int,string> stationName;

   public: 
   DelhiMetro(int v);
void addStation(int id,string name);
void displayStations(); 

};


#endif