#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int rec(int steps, int target, vector<int> &dp)
    {
        if (steps > target)
        {
            return 0;
        }
        if (steps == target)
        {
            return 1;
        }

        if(steps == target -1){
            return 1;
        }

        if (dp[steps] != -1)
        {
            return dp[steps];
        }

        int count = 0;
        for (int i = 1; i <= 2; i++)
        {
            count += rec(steps + i, target, dp);
        }
        return dp[steps] = count;
    }

public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        int count = rec(0, n, dp);
        for(auto it: dp){
            cout << it << " ";
        }
        return count;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution sol;
    int result = sol.climbStairs(n);

    cout << result << endl;

    return 0;
}
