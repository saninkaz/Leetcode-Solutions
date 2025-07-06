#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {

        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int res = 0;

        int i = 0, j = 0;
        int n = g.size();
        int m = s.size();

        while (i < m && j < n)
        {
            if (s[i] >= g[j]){
                j++;
            }
            i++;
        }
        return j; 
    }
};

int main()
{
    Solution sol;

    vector<int> g = {1, 2, 3}; // Greed factors of children
    vector<int> s = {1, 1};    // Sizes of cookies

    int result = sol.findContentChildren(g, s);
    cout << "Maximum number of content children: " << result << endl;

    return 0;
}
