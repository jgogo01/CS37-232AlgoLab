#include <iostream>
using namespace std;

int pumpTheGas(int gas[], int consume[], int n)
{
    int totalGas = 0;
    int currentGas = 0;
    int startStation = 0;
    for (int i = 0; i < n; i++)
    {
        currentGas += gas[i] - consume[i];
        totalGas += gas[i] - consume[i];

        if (currentGas < 0)
        {
            currentGas = 0;
            startStation = i + 1;
        }
    }

    if (totalGas >= 0)
    {
        return startStation;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;

    if (n <= 0)
    {
        cout << -1;
        return 0;
    }

    int gas[n];
    int consume[n];

    for (int i = 0; i < n; i++)
    {
        int _gas;
        cin >> _gas;
        gas[i] = _gas;
    }

    for (int i = 0; i < n; i++)
    {
        int _consume;
        cin >> _consume;
        consume[i] = _consume;
    }

    cout << pumpTheGas(gas, consume, n);

    return 0;
}
