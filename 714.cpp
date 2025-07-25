#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int rec(int i, int buy, vector<int> &prices, int n, int fee, vector<vector<int>> &dp)
    {
        if (i == n)
        {
            return 0;
        }

        if (dp[i][buy] != -1)
        {
            return dp[i][buy];
        }

        if (buy)
        {
            int take = -prices[i] + rec(i + 1, 0, prices, n, fee, dp);
            int notTake = rec(i + 1, 1, prices, n, fee, dp);
            return dp[i][buy] = max(take, notTake);
        }
        else
        {
            int take = prices[i]-fee + rec(i + 1, 1, prices, n, fee, dp);
            int notTake = rec(i + 1, 0, prices, n, fee, dp);
            return dp[i][buy] = max(take, notTake);
        }
    }

public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return rec(0, 1, prices, n, fee, dp);
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    int result = sol.maxProfit(prices, fee);
    cout << "Maximum Profit: " << result << endl;

    return 0;
}
