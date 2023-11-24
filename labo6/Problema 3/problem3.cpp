#include <iostream>
using namespace std;

int minActors(int *salaries, int budget, int n)
{
    int dp[budget + 1];

    for (int i = 0; i <= budget; i++)
    {
        dp[i] = budget + 1;
    }

    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = salaries[i]; j <= budget; j++)
        {
            if (dp[j - salaries[i]] != n + 1)
            {
                dp[j] = min(dp[j], dp[j - salaries[i]] + 1);
            }
        }
    }

    return dp[budget] != budget + 1 ? dp[budget] : -1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int budget, n;
        cin >> budget;
        cin >> n;

        int *salaries = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> salaries[i];
        }

        int result = minActors(salaries, budget, n);
        cout << result << endl;

        // Liberar la memoria asignada al array dinámico
        delete[] salaries;
    }

    return 0;
}

/* 
    input:
    2 // CASES
    20
    4
    2 1 5 10
    output:
    2
    input:
    15  
    5
    1 5 3 2 7
    output:
    3
*/