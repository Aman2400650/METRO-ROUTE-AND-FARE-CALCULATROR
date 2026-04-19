#ifndef METRO_H
#define METRO_H

#include <string>
#include <map>
#include <vector>

using namespace std;

// Structure to store route details
struct Edge {
    int to;
    int time;
    int fare;
};

class DelhiMetro {
    int V; // Number of stations
    map<int, string> stationNames;
    vector<vector<Edge>> adj;

public:
    DelhiMetro(int v);
    void addStation(int id, string name);
    void addRoute(int u, int v, int time, int fare); 
    void displayStations(); 
    void findShortestRoute(int start, int end);
};

#endif
