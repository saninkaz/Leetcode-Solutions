#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // private:
    //     bool rec(int i, int j, string s, string p, vector<vector<int>> &dp)
    //     {
    //         if (j < 0)
    //             return i < 0;
    //         if (i < 0 && j >= 0)
    //         {
    //             for (int k = 0; k <= j; k++)
    //             {
    //                 if (p[k] != '*')
    //                     return false;
    //             }
    //             return true;
    //         }

    //         if (dp[i][j] != -1)
    //         {
    //             return dp[i][j];
    //         }

    //         if (s[i] == p[j] || p[j] == '?')
    //         {
    //             return dp[i][j] = rec(i - 1, j - 1, s, p, dp);
    //         }

    //         if (p[j] == '*')
    //         {
    //             return dp[i][j] = rec(i - 1, j, s, p, dp) | rec(i, j - 1, s, p, dp);
    //         }

    //         return dp[i][j] = false;
    //     }

public:
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();

        // TABULATION

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        for (int j = 1; j <= m; j++)
        {
            if (p[j - 1] == '*')
            {
                dp[0][j] = dp[0][j - 1];
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                else if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};

int main()
{
    Solution sol;

    string s = "aa";
    string p = "*";

    cout << boolalpha << sol.isMatch(s, p) << endl;

    return 0;
}
