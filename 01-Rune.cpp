// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
    int numRune;
    int maxRune;
    cin >> numRune;
    cin >> maxRune;
    int rune[numRune];
    
    for(int i = 0; i < numRune; i++){
        int temp;
        cin >> temp;
        rune[i] = temp;
    }
    
    //Sort
    int len = sizeof(rune)/sizeof(rune[0]);
    std::sort(rune, rune + len);
    
    //Find Dif (min)
    int min = 0;
    for(int j = 0; j < maxRune; j++){
        min += rune[j];
    }
    
    //Find Dif (max)
    int max = 0;
    for(int j = (numRune-1); j > (numRune-1)-maxRune; j--){
        max += rune[j];
    }
    
    cout << max - min;
}