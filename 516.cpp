#include <bits/stdc++.h>
using namespace std;

// Tabulation

// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         int n = s.length();
        
//         vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

//         for (int j = 0; j <= n; j++)
//             dp[0][j] = 0;

//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= n; j++) 
//             {
//                 if (s[i - 1] == s[n-j])
//                     dp[i][j] = 1 + dp[i-1][j - 1];
//                 else
//                 {
//                     dp[i][j] = max(dp[i-1][j], dp[i][j - 1]);
//                 }
//             }
//         }

//         return dp[n][n];

//     }
// };

// Space optimized

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();

        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int j = 0; j <= n; j++)
            prev[j] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == s[n - j])
                    curr[j] = 1 + prev[j - 1];
                else
                {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }

        return prev[n];
    }
};

int main()
{
    Solution sol;
    string s = "bbbab";
    cout << sol.longestPalindromeSubseq(s) << endl;
    return 0;
}
