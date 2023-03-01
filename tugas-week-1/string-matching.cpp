#include <bits/stdc++.h>
using namespace std;

int string_matching(string teks, string pattern, int n, int m){
    int i, j, idx;
    bool found = false;
    i = 0;
    idx = -1;
    while(i <= n - m && !found){
        j = 0;
        while(j < m && teks[i+j] == pattern[j]){
            j++;
        }

        if(j == m){
            found = true;
            idx = i;
        }

        i++;
    }
    return idx;
}

int main() {
    string teks = "Hai Sayang";
    string pattern = "Say";
    cout << string_matching(teks, pattern, teks.size(), pattern.size());
    return 0;
}