#include "metro.h"
#include<iostream>

DelhiMetro::DelhiMetro(int v):V(v){}

void DelhiMetro::addStation(int id,string name){
    stationName[id]=name;
}
void DelhiMetro::displayStations(){
    for(auto const& p : stationName){
    cout << p.first << "-->" << p.second << endl;
}
}