#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {

        stack<char> st;
        string res;
        int n = num.size();
        if (k == n)
        {
            return "0";
        }

        for (int i = 0; i < n; i++)
        {

            while (st.size() && k > 0 && num[i] < st.top())
            {
                k--;
                st.pop();
            }

            st.push(num[i]);
        }

        while (k > 0 && st.size())
        {
            st.pop();
            k--;
        }

        while (st.size())
        {
            res.push_back(st.top());
            st.pop();
        }

        while (res.size() && res.back() == '0')
        {
            if (res.size() == 1)
            {
                return res;
            }

            res.pop_back();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution sol;

    // Example 1
    string num1 = "1432219";
    int k1 = 3;
    cout << sol.removeKdigits(num1, k1) << endl; // Expected: "1219"

    // Example 2
    string num2 = "10200";
    int k2 = 1;
    cout << sol.removeKdigits(num2, k2) << endl; // Expected: "200"

    // Example 3
    string num3 = "10";
    int k3 = 1;
    cout << sol.removeKdigits(num3, k3) << endl; // Expected: "0"

    return 0;
}
