#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.length();
        vector<int> mpp(27);
        int maxLen = 0;
        int maxFreq = 0;

        int j = 0;

        for (int i = 0; i < n; i++)
        {
            mpp[s[i]-'A']++;
            maxFreq = max(maxFreq, mpp[s[i]-'A']);

            if ((i - j + 1) - maxFreq > k)
            {
                mpp[s[j]-'A']--;
                j++;
            }
            if ((i - j + 1) - maxFreq <= k)
            {
                maxLen = max(maxLen, i - j + 1);
            }
        }

        return maxLen;
    }
};

int main()
{
    Solution sol;

    // Sample input
    string s = "AABABBA";
    int k = 1;

    // Call the function and print the result
    int result = sol.characterReplacement(s, k);
    cout << "Longest substring length: " << result << endl;

    return 0;
}
