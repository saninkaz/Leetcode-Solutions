#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.length();
        int m = text2.length();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int j = 0; j <= m; j++)
            prev[j] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }

        return prev[m];
    }

public:
    int minDistance(string word1, string word2)
    {
        int m = word1.length();
        int n = word2.length();

        return ((n+m) - (2 * longestCommonSubsequence(word1, word2)));
    }
};

int main()
{
    Solution sol;
    string word1 = "sea";
    string word2 = "eat";
    cout << sol.minDistance(word1, word2) << endl; // Sample Output: 2
    return 0;
}
