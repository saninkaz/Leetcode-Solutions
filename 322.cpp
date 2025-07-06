#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int MOD = 1e9;

private:
    int rec(int index, vector<int> &coins, int target, vector<vector<int>> &dp)
    {
        if (target == 0)
        {
            return 0;
        }
        if (index == 0)
        {
            if (target % coins[index] == 0)
            {
                return target / coins[index];
            }
            else
            {
                return MOD;
            }
        }

        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }

        int notTake = rec(index - 1, coins, target, dp);
        int take = INT_MAX;
        if (coins[index] <= target)
        {
            take = 1 + rec(index, coins, target - coins[index], dp);
        }

        return dp[index][target] = min(take, notTake);
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

        if (amount == 0) 
            return 0;

            // TABULATION

        for (int t = 0; t <= amount; t++)
        {
            if (t % coins[0] == 0)
            {
                dp[0][t] = t / coins[0];
            }
            else{
                dp[0][t]= MOD;
            }
        }

        for (int index = 1; index < n; index++)
        {
            for (int t = 0; t <= amount; t++)
            {
                int notTake = dp[index - 1][t];
                int take = MOD;
                if (coins[index] <= t)
                {
                    take = 1 + dp[index][t - coins[index]];
                }

                dp[index][t] = min(take, notTake);
            }
        }

        if (dp[n - 1][amount] == 1e9)
            return -1;
        return dp[n - 1][amount];
    }
};

int main()
{
    int n, amount;
    cout << "Enter number of coin types: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter coin denominations:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> coins[i];
    }

    cout << "Enter amount: ";
    cin >> amount;

    Solution sol;
    int result = sol.coinChange(coins, amount);

    cout << "Fewest number of coins needed: " << result << endl;

    return 0;
}
