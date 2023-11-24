#include <iostream>
using namespace std;

// Function to find the maximum sum subsequence of non-negative integers
int maxSumSubsequence(int arr[], int n)
{
    int maxSum[n+1];
    int currSum = 0;
    maxSum[0] = 0;
    // Iterate through the array elements
    for (int i = 1; i <= n; i++)
    {
        // Update the current sum considering the current element
        // If the current sum becomes negative, reset it to 0
        currSum = max(currSum + arr[i-1] , arr[i-1]);
        // Update the maximum sum if the current sum is greater
        maxSum[i] = max(currSum, maxSum[i-1]);
    }
    return maxSum[n];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int jars[n];
        // Input the elements into the array
        for (int i = 0; i < n; i++)
        {
            cin >> jars[i];
        }
        int maxStrawberry = maxSumSubsequence(jars, n);
        cout << maxStrawberry << "\n";
    }
    return 0;
}
/*
    input
    1
    5
    2 -3 5 -1 4
    output
    8
*/
