#include <bits/stdc++.h>
using namespace std;

class Solution
{

    // RECURSION

    // private:
    //     int
    //     rec(int i, int j, string s, string t, vector<vector<int>> &dp)
    //     {
    //         if (j == 0)
    //             return 1;
    //         if (i == 0)
    //             return 0;

    //         if (dp[i][j] != -1)
    //         {
    //             return dp[i][j];
    //         }

    //         if (s[i - 1] == t[j - 1])
    //         {
    //             return dp[i][j] = rec(i - 1, j - 1, s, t, dp) + rec(i - 1, j, s, t, dp);
    //         }

    //         return dp[i][j] = rec(i - 1, j, s, t, dp);
    //     }

public:
    int numDistinct(string s, string t)
    {
        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // TABULATION

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][m];
    }
};

int main()
{
    Solution sol;

    // Sample input
    string s = "rabbbit";
    string t = "rabbit";

    // Function call
    int result = sol.numDistinct(s, t);

    // Output result
    cout << "Number of distinct subsequences: " << result << endl;

    return 0;
}
