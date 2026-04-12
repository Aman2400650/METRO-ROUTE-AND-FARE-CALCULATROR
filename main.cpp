#include <iostream>
#include <vector>
#include <algorithm>
#include "metro.h"

using namespace std;

int main() {
    DelhiMetro dm(50);
    //call
    
    // Blue Line
    dm.addStation(0, "Dwarka Sec-21");
    dm.addStation(7, "Rajiv Chowk");
    dm.addStation(15, "Mandi House");
    dm.addStation(10, "Yamuna Bank");
    dm.addStation(11, "Laxmi Nagar");
 // Yellow Line
    dm.addStation(24, "Kashmere Gate");
    dm.addStation(26, "New Delhi");

      // Red Line
    dm.addStation(38, "Inderlok");
    dm.displayStations();
    return 0;
}