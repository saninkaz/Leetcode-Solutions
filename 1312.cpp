#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
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
public:
    int minInsertions(string s) {
        int lps = longestPalindromeSubseq(s);
        return (s.length()-lps);
    }
};

int main() {
    Solution sol;
    string s = "mbadm"; // Sample input
    cout << sol.minInsertions(s) << endl;
    return 0;
}
