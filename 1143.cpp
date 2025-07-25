#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int rec(int i, int j, string text1, string text2, vector<vector<int>> &dp)
    {
        if (i == text1.size() || j == text2.size())
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (text1[i] == text2[j])
        {
            return dp[i][j] = 1 + rec(i + 1, j + 1, text1, text2, dp);
        }
        else
        {
            return dp[i][j] = max(rec(i, j + 1, text1, text2, dp), rec(i + 1, j, text1, text2, dp));
        }
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return rec(0, 0, text1, text2, dp);
    }
};

int main()
{
    Solution sol;

    string text1 = "abcde";
    string text2 = "ace";

    int result = sol.longestCommonSubsequence(text1, text2);
    cout << "Length of LCS: " << result << endl;

    return 0;
}
