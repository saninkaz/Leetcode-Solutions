#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int rec(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
    {
        if (j < 0)
            return i + 1;
        if (i < 0)
            return j + 1;

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (word1[i] == word2[j])
        {
            return dp[i][j] = rec(i - 1, j - 1, word1, word2, dp);
        }

        return dp[i][j] = 1 + min(rec(i - 1, j - 1, word1, word2, dp), min(rec(i - 1, j, word1, word2, dp), rec(i, j - 1, word1, word2, dp)));
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        int res = rec(n - 1, m - 1, word1, word2, dp);

        return res;
    }
};

int main()
{
    Solution sol;
    string word1 = "horse";
    string word2 = "ros";
    cout << sol.minDistance(word1, word2) << endl;
    return 0;
}
