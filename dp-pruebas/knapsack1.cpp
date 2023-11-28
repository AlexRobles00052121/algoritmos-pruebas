#include <iostream>
using namespace std;

void knapsack(int capacity, int n, int values[], int weights[]) {
    int maxSubset = 1 << n;
    int maxVal = 0, bestSubset = 0;

    for (int subset = 0; subset < maxSubset; subset++) {
        int currentWeight = 0, currentValue = 0;

        for (int i = 0; i < n; i++) {
            if ((subset & (1 << i)) != 0) {
                currentWeight += weights[i];
                currentValue += values[i];
            }
        }

        if (currentWeight <= capacity && currentValue > maxVal) {
            maxVal = currentValue;
            bestSubset = subset;
        }
    }

    // Count the number of items in the best subset
    int itemCount = 0;
    for (int i = 0; i < n; i++) {
        if ((bestSubset & (1 << i)) != 0) {
            itemCount++;
        }
    }

    // Output the results
    cout << itemCount << endl;
    for (int i = 0; i < n; i++) {
        if ((bestSubset & (1 << i)) != 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {

        int capacity, n;
        cin >> capacity >> n;

        int values[n], weights[n];
        for (int i = 0; i < n; i++) {
            cin >> values[i] >> weights[i];
        }

        knapsack(capacity, n, values, weights);
    
}