#include <bits/stdc++.h>
using namespace std;

void knapsack(int n, int k, vector<int> w, vector<int> p) {
    int res = -1, maxP = -1;
    for(int i = 0; i < (1 << n); i++){
        int tw=0, tp=0;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                tw += w[j];
                tp += p[j];
            }
        }

        if(tw <= k && tp > maxP){
            maxP = tp;   
            res = i; 
        }
    }

    if(res != -1){
        for(int i = 0; i < n; i++){
            if(res & (1 << i)){
                cout << 1;
            } else{
                cout << 0;
            }
        }
    } else{
        cout << "Tidak ada solusi";
    }
}

int main() {
    int n = 4, k = 16;
    vector<int> w = {2,5,10,5};
    vector<int> p = {20,30,50,10}; 
    knapsack(n, k, w, p);
    return 0;
}