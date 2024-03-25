#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int g_max;
int a[3] = {5, -2, 3};

int MCSS(int n){
    //First Position
    if(n == 0) {
        g_max = a[0];
        return a[0];
    }else{
        //Find Max (Reversed+Now or Now) at Current State
        int temp = max(MCSS(n-1)+a[n], a[n]);
        //Change Value Gobal var.
        g_max = max(g_max, temp);
        return temp;
    }
}

int main() {
    MCSS(2);
    cout << g_max << endl;
}