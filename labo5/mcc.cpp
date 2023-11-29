#include <bits/stdc++.h>

using namespace std;

// { Driver Code Starts

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

int dp[101][1001][101];

class Solution {
public:
    
    bool makeChanges(int N, int K, int target, const std::vector<int> &coins) { // Check if it's possible to make change with exactly K coins to reach the target

        std::vector<std::vector<bool>> dp(K + 1, std::vector<bool>(target + 1, false)); // Dynamic programming table to store subproblem results.

        // Base case: With 0 coins and 0 target, it's always possible.
        dp[0][0] = true;

        // Iterate over each coin.
        for (int i = 1; i <= N; ++i) {
            for (int k = 1; k <= K; ++k) {
                // Iterate over the target.
                for (int j = coins[i - 1]; j <= target; ++j) {
                    dp[k][j] = dp[k][j] || dp[k - 1][j - coins[i - 1]]; // Update dp[k][j] if we can make the change with the current coin
                }
            }
        }

        // Final result: Is it possible to make the change with exactly K coins to reach the target?
        return dp[K][target];
    }
};

// { Driver Code Starts

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);
        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends