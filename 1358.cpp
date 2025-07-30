#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.length();
        vector<int> lastSeen = {-1, -1, -1};
        int total = 0;

        for (int i = 0; i < n; i++)
        {
            lastSeen[s[i] - 'a'] = i;

            total += (1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2])));
        }

        return total;
    }
};

int main()
{
    Solution sol;

    // Sample input
    string s = "abcabc";

    // Call the function and print the result
    int result = sol.numberOfSubstrings(s);
    cout << "Number of valid substrings: " << result << endl;

    return 0;
}
