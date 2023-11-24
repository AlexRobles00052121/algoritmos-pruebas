#include <iostream>

using namespace std;

// Function to calculate the minimum amount of vitamins using dynamic programming
int min_vitamins(int vitamins[], int V, int maximum) {
    // Create an array to store the minimum number of vitamins needed for each speed
    int dp[maximum + 1];
    
    // Initialize the array with values greater than the maximum possible vitamins needed
    for (int i = 0; i <= maximum; i++) {
        dp[i] = maximum + 1;
    }
    
    // Base case: No vitamins needed for speed 0
    dp[0] = 0;
    
    // Iterate through each vitamin and update the array based on the minimum vitamins needed
    for (int i = 0; i < V; i++) {
        for (int j = vitamins[i]; j <= maximum; j++) {
            // Check if the current vitamin helps achieve a lower number of vitamins for the current speed
            if (dp[j - vitamins[i]] != maximum + 1)
                dp[j] = min(dp[j], dp[j - vitamins[i]] + 1);
        }
    }
    
    // Return the minimum vitamins needed for the maximum speed, or -1 if not possible
    return dp[maximum] != maximum + 1 ? dp[maximum] : -1;
}

int main() {
    int T; // Number of test cases
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int G, V; // Gauge and number of vitamins
        cin >> G;
        cin >> V;

        int vitamins[V]; // Array to store the vitamins
        for (int i = 0; i < V; ++i) {
            cin >> vitamins[i];
        }

        // Calculate and display the minimum amount of vitamins
        int result = min_vitamins(vitamins, V, G);
        if (result != -1)
            cout << result << endl;
        else
            cout << "It is not possible to reach the maximum speed with the given vitamins.\n\n";
    }

    return 0;
}

/*
    input:
    1
    100
    5
    20 25 10 50 1
    output:
    2
*/