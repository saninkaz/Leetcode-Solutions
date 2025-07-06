#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // private:
    //     int rec(int index, vector<int> &coins, int amount, vector<vector<int>> &dp)
    //     {
    //         if (index == 0)
    //         {
    //             if (amount % coins[index] == 0)
    //             {
    //                 return 1;
    //             }
    //             else
    //             {
    //                 return 0;
    //             }
    //         }

    //         if (dp[index][amount] != -1)
    //         {
    //             return dp[index][amount];
    //         }

    //         int notTake = rec(index - 1, coins, amount, dp);
    //         int take = 0;
    //         if (coins[index] <= amount)
    //         {
    //             take = rec(index, coins, amount - coins[index], dp);
    //         }

    //         return dp[index][amount] = take + notTake;
    //     }

public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // TABULATION

        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                dp[0][i] = 1;
        }

        for (int index = 1; index < n; index++)
        {
            for (int t = 0; t <= amount; t++)
            {
                long notTake = dp[index - 1][t];
                long take = 0;
                if (coins[index] <= t)
                {
                    take = dp[index][t - coins[index]];
                }

                dp[index][t] = (take + notTake);
            }
        }

        // int res = rec(n - 1, coins, amount, dp);

        return dp[n - 1][amount];
    }
};

int main()
{
    Solution sol;

    // Sample input
    int amount = 5;
    vector<int> coins = {1, 2, 5};

    // Function call
    int result = sol.change(amount, coins);

    // Output result
    cout << "Number of combinations: " << result << endl;

    return 0;
}
