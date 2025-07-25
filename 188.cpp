#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int rec(int i, int j, vector<int> &prices, int n, int count, vector<vector<vector<int>>> &dp)
    {
        if (count == 0)
        {
            return 0;
        }
        if (i == n)
        {
            return 0;
        }

        if (dp[i][j][count] != -1)
        {
            return dp[i][j][count];
        }

        if (j)
        {
            int take = -prices[i] + rec(i + 1, 0, prices, n, count, dp);
            int notTake = rec(i + 1, 1, prices, n, count, dp);
            return dp[i][j][count] = max(take, notTake);
        }
        else
        {
            int take = prices[i] + rec(i + 1, 1, prices, n, count - 1, dp);
            int notTake = rec(i + 1, 0, prices, n, count, dp);
            return dp[i][j][count] = max(take, notTake);
        }
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0 || k == 0)
        {
            return 0;
        }

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));

        return rec(0, 1, prices, n, k, dp);
    }
};

int main()
{
    Solution sol;

    int k = 2;
    vector<int> prices = {3, 2, 6, 5, 0, 3};

    int result = sol.maxProfit(k, prices);
    cout << "Max Profit: " << result << endl;

    return 0;
}
