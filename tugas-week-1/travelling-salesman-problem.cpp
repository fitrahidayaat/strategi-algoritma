#include <bits/stdc++.h>
using namespace std;

void tspBruteForce(vector<vector<int>>& distances) {
    int n = distances.size();
    vector<int> route(n);
    for (int i = 0; i < n; i++) {
        route[i] = i;
    }
    int shortestDistance = INT_MAX;
    vector<int> shortestRoute(n);
    do {
        for(int i = 0; i < n; i++){
            cout << route[i] << " ";
        }
        cout << "\n";
        int distance = 0;
        int n = route.size();
        for (int i = 0; i < n - 1; i++) {
            distance += distances[route[i]][route[i+1]];
        }
        distance += distances[route[n-1]][route[0]];
        if (distance < shortestDistance) {
            shortestDistance = distance;
            shortestRoute = route;
        }
    } while (next_permutation(route.begin()+1, route.end()));
    cout << "Shortest route: ";
    for (int i = 0; i < n; i++) {
        cout << shortestRoute[i] << " ";
    }
    cout << "\nShortest distance: " << shortestDistance << endl;
}

int main() {
    vector<vector<int>> distances = {
        { 0, 10, 15, 20 },
        { 10, 0, 35, 25 },
        { 15, 35, 0, 30 },
        { 20, 25, 30, 0 }
    };
    tspBruteForce(distances);
    return 0;
}