#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int rec(int i, int buy, vector<int> &prices, int n, vector<vector<int>> &dp)
    {
        if (i >= n)
        {
            return 0;
        }

        if (dp[i][buy] != -1)
        {
            return dp[i][buy];
        }

        if (buy)
        {
            int take = -prices[i] + rec(i + 1, 0, prices, n, dp);
            int notTake = rec(i + 1, 1, prices, n, dp);
            return dp[i][buy] = max(take, notTake);
        }
        else
        {
            int take = prices[i] + rec(i + 2, 1, prices, n, dp);
            int notTake = rec(i + 1, 0, prices, n, dp);
            return dp[i][buy] = max(take, notTake);
        }
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return rec(0, 1, prices, n, dp);
    }
};

int main()
{
    Solution sol;

    vector<int> prices1 = {1, 2, 3, 0, 2};
    cout << "Max profit (Test 1): " << sol.maxProfit(prices1) << endl; // Output: 3

    vector<int> prices2 = {1};
    cout << "Max profit (Test 2): " << sol.maxProfit(prices2) << endl; // Output: 0

    vector<int> prices3 = {2, 1, 4};
    cout << "Max profit (Test 3): " << sol.maxProfit(prices3) << endl; // Output: 3

    return 0;
}
