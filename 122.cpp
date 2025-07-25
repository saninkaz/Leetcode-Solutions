#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int rec(int i, int buy, vector<int> &prices, int n, vector<vector<int>> &dp)
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
            int take = -prices[i] + rec(i + 1, 0, prices, n,dp);
            int notTake = rec(i + 1, 1, prices, n,dp);
            return dp[i][buy] = max(take, notTake);
        }
        else
        {
            int take = prices[i] + rec(i + 1, 1, prices, n,dp);
            int notTake = rec(i + 1, 0, prices, n,dp);
            return dp[i][buy] = max(take, notTake);
        }
    }

public:
    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int ans = rec(0, 1, prices, n, dp);
        return ans;
    }
};

int main()
{
    Solution sol;

    // Sample input 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Output: " << sol.maxProfit(prices1) << endl;

    // Sample input 2
    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "Output: " << sol.maxProfit(prices2) << endl;

    // Sample input 3
    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << "Output: " << sol.maxProfit(prices3) << endl;

    return 0;
}
