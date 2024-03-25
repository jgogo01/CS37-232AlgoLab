#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int MCSS(int x[], int len){
    int lookup[len];
    //Best Case
    lookup[0] = x[0];
    //Loop Create Arr
    for(int i = 0; i < len; i++){
        lookup[i] = max(x[i-1]+lookup[i], lookup[i]);
    }
    
    //Def Value Max
    int max = lookup[0];
    //Loop Find Max in Lookup
    for(int j = 0; j < len; j++){
        if(lookup[j] > max){
            max = lookup[j];
        }
    }
    return max;
}

int main() {
    int x[3] = {5, -2, 3};
    int max = MCSS(x, 2);
    cout << max << endl;
}