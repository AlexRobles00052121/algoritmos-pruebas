#include <iostream>
using namespace std;

const int MAX_SIZE = 101;

const int MAX_INT = (1 << 30) - 1;

int matrixChainMultiplication(int dimensions[MAX_SIZE][2], int n) {
    int dp[MAX_SIZE][MAX_SIZE];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = MAX_INT;
        }
    }

    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    // Llenar la matriz dp usando programación dinámica
    for (int len = 2; len < n; len++) {
        for (int i = 1; i <= n - len; i++) {
            int j = i + len - 1;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i][0] * dimensions[k][1] * dimensions[j][1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    int n;
    cin >> n;

    int dimensions[MAX_SIZE][2];
    for (int i = 1; i <= n; i++) {
        cin >> dimensions[i][0] >> dimensions[i][1];
    }

    int result = matrixChainMultiplication(dimensions, n + 1);
    cout << result << endl;

    return 0;
}
