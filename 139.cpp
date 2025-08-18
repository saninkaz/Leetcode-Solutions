#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int rec(int i, string &s, string &temp, int n,
            vector<string> &wordDict, vector<int> &dp,
            unordered_map<string, int> &mpp)
    {

        if (mpp.find(temp) != mpp.end())
        {
            return 1;
        }

        if (i >= n)
        {
            return 0;
        }

        int notPick = rec(i + 1, s, temp, n, wordDict, dp, mpp);

        temp.push_back(s[i]);
        cout << temp << " "; // Debug output
        int pick = rec(i + 1, s, temp, n, wordDict, dp, mpp);
        temp.pop_back();

        cout << pick << notPick << " ";

        return pick + notPick;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.length();
        unordered_map<string, int> mpp;

        for (int i = 0; i < wordDict.size(); i++)
        {
            mpp[wordDict[i]] = 1;
        }

        vector<int> dp(n + 1, -1);
        string temp = "";

        int ans = rec(0, s, temp, n, wordDict, dp, mpp);
        cout << "\nTotal matches found: " << ans << "\n";
        return ans == (int)wordDict.size();
    }
};

int main()
{
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    Solution sol;
    bool result = sol.wordBreak(s, wordDict);

    cout << "WordBreak result: " << (result ? "true" : "false") << "\n";
    return 0;
}
