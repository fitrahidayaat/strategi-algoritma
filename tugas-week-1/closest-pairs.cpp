#include <bits/stdc++.h>
using namespace std;

struct point{
    double x, y;
};

void closestPairs(point P[], int n, point &p1, point &p2) {
    double d, dmin;
    dmin = DBL_MAX;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            d = sqrt((P[i].x - P[j].x)*(P[i].x - P[j].x) + (P[i].y - P[j].y)*((P[i].y - P[j].y)));
            if(d < dmin){
                dmin = d;
                p1 = P[i];
                p2 = P[j];
            }
        }
    }
}

int main() {
    int n; cin >> n;
    point P[n];
    for(int i = 0; i < n; i++){
        cin >> P[i].x >> P[i].y;
    }
    point p1, p2;
    closestPairs(P, n, p1, p2);
    cout << p1.x << " " << p1.y << "\n" << p2.x << " " << p2.y;
    return 0;
}