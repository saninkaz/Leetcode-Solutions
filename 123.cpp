#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int rec(int i, int j, vector<int> &prices, int n, int count, vector<vector<vector<int>>> &dp)
    {
        if (count == 2)
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
            int take = prices[i] + rec(i + 1, 1, prices, n, count + 1, dp);
            int notTake = rec(i + 1, 0, prices, n, count, dp);
            return dp[i][j][count] = max(take, notTake);
        }
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;
        int count = 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        int ans = rec(0, 1, prices, n, count, dp);

        return ans;
    }
};

int main()
{
    Solution sol;

    // Example 1
    vector<int> prices1 = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << "Output: " << sol.maxProfit(prices1) << endl;

    // Example 2
    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "Output: " << sol.maxProfit(prices2) << endl;

    // Example 3
    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << "Output: " << sol.maxProfit(prices3) << endl;

    return 0;
}
