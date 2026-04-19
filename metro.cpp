#include "metro.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Constructor: Initializing Adjacency List
DelhiMetro::DelhiMetro(int v) : V(v) {
    adj.resize(v); 
}

void DelhiMetro::addStation(int id, string name) {
    stationNames[id] = name;
}

// Bidirectional routing
void DelhiMetro::addRoute(int u, int v, int time, int fare) {
    if (u < V && v < V) {
        adj[u].push_back({v, time, fare});
        adj[v].push_back({u, time, fare});
    }
}

void DelhiMetro::displayStations() {
    cout << "\n--- AVAILABLE METRO STATIONS ---" << endl;
    for (auto const& [id, name] : stationNames) {
        cout << "[" << id << "] " << name << endl;
    }
}

void DelhiMetro::findShortestRoute(int start, int end) {
    // Validation
    if (stationNames.find(start) == stationNames.end() || stationNames.find(end) == stationNames.end()) {
        cout << "\n[Error] Invalid Station ID entered!" << endl;
        return;
    }

    // Dijkstra's Requirements
    vector<int> dist(V, 2147483647); // Initializing with INT_MAX
    vector<int> parent(V, -1);
    vector<int> totalFare(V, 0);
    
    // Min-Priority Queue (Priority based on Time)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Optimization: Stop if destination is reached
        if (u == end) break; 

        // Skip if a better path is already processed
        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            // Relaxation Step
            if (dist[edge.to] > dist[u] + edge.time) {
                dist[edge.to] = dist[u] + edge.time;
                totalFare[edge.to] = totalFare[u] + edge.fare;
                parent[edge.to] = u;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }

    // Output Result
    if (dist[end] == 2147483647) {
        cout << "\nRoute not found!" << endl;
    } else {
        cout << "\n================================" << endl;
        cout << "      JOURNEY SUMMARY           " << endl;
        cout << "================================" << endl;
        cout << "TIME: " << dist[end] << " mins" << endl;
        cout << "FARE: Rs. " << totalFare[end] << endl;
        
        // Path Reconstruction
        vector<int> path;
        for (int v = end; v != -1; v = parent[v]) path.push_back(v);
        reverse(path.begin(), path.end());

        cout << "\nOPTIMAL ROUTE:" << endl;
        for (int i = 0; i < path.size(); i++) {
            cout << stationNames[path[i]] << (i == path.size() - 1 ? "" : " -> ");
        }
        cout << "\n\nTotal Stations: " << path.size();
        cout << "\n================================\n";
    }
}
