#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.length();
        int m = t.length();

        int j = 0;
        int sIndex = -1;
        int minLength = INT_MAX;
        int count = 0;
        vector<int> mpp(257);

        for (int i = 0; i < m; i++)
        {
            mpp[t[i] - 'A']++;
        }

        for (int i = 0; i < n; i++)
        {
            if (mpp[s[i] - 'A'] > 0)
            {
                count++;
            }
            mpp[s[i] - 'A']--;
            while (count == m)
            {
                if (i - j + 1 < minLength)
                {
                    minLength = i - j + 1;
                    sIndex = j;
                }
                mpp[s[j] - 'A']++;
                if (mpp[s[j] - 'A'] > 0)
                    count--;
                j++;
            }
        }

        return sIndex == -1 ? "" : s.substr(sIndex, minLength);
    }
};

int main()
{
    Solution sol;

    string s = "ADOBECODEBANC";
    string t = "ABC";

    string result = sol.minWindow(s, t);
    cout << "Minimum window: " << result << endl;

    return 0;
}
