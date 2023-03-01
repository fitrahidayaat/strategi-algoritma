#include <bits/stdc++.h>
using namespace std;

double polinom(int a[], int n, double x){
    int p = 0, pangkat;
    for(int i = n; i >= 0; i--){
        pangkat = 1;
        for(int j = 1; j <= i; j++){
            pangkat *= x;
        }
        p = p + a[i]*pangkat;
    }
    return p;
}

double polinom2(int a[], int n, double x){
    int p = a[0], pangkat = 1;
    for(int i = 1; i <= n; i++){
        pangkat *= x;
        p = p + a[i]*pangkat;
    }
    return p;
}

int main() {
    int a[] = {1,2,3}; // 3x^2 + 2x + 1
    int n = 2;
    double x = 2;
    cout << polinom(a, n, x) << " " << polinom2(a, n, x);
    return 0;
}