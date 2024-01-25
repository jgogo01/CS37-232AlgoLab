#include <iostream>
#include <algorithm> 

using namespace std;

int main() {
    int numPeople = 0;
    int maxWeight = 0;
    cin >> numPeople;
    cin >> maxWeight;
    int weight[numPeople];
    
    for(int i = 0; i < numPeople; i++){
        int temp;
        cin >> temp;
        weight[i] = temp;
    }
    
    // Sort
    int len = numPeople; // Corrected the calculation of the array length
    std::sort(weight, weight + len);
    
    // Calculate the number of trips needed
    int firstIndex = 0;
    int lastIndex = numPeople - 1; // Corrected to avoid accessing an out-of-bounds index
    int count = 0;
    
    while (firstIndex <= lastIndex) {
        if (weight[firstIndex] + weight[lastIndex] <= maxWeight) {
            count++;
            firstIndex++;
            lastIndex--;
        } else {
            count++;
            lastIndex--;
        }
    }
    
    cout << count << endl;
    
    return 0;
}
