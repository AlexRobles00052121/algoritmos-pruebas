#include <iostream>
#include <climits>
using namespace std;

int maxSumSubsequence(int arr[], int n)
{
    int maxSum = 0;
    int currSum = 0;

    for (int i = 0; i < n; i++)
    {
        currSum = max(0, currSum + arr[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
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
        for (int i = 0; i < n; i++)
        {
            cin >> jars[i];
        }

        int maxStrawberry = maxSumSubsequence(jars, n);

        cout << maxStrawberry << "\n";
    }

    return 0;
}