#include <bits/stdc++.h>
using namespace std;

// class Solution
// {

// private:
//     vector<vector<int>> dp;
//     bool check(int i, string &s, int count, int n)
//     {
//         if (i == n)
//         {
//             return count == 0;
//         }

//         if (count < 0)
//         {
//             return false;
//         }
//         if (dp[i][count] != -1)
//         {
//             return dp[i][count];
//         }

//         if (s[i] == '(')
//         {
//             if (check(i + 1, s, count + 1, n))
//                 return dp[i][count] = true;
//         }
//         else if (s[i] == ')')
//         {
//             if (check(i + 1, s, count - 1, n))
//                 return dp[i][count] = true;
//         }

//         else if (s[i] == '*')
//         {

//             if (check(i + 1, s, count + 1, n))
//                 return dp[i][count] = true;

//             if (check(i + 1, s, count, n))
//                 return dp[i][count] = true;
//             if (check(i + 1, s, count - 1, n))
//                 return dp[i][count] = true;
//         }

//         return dp[i][count] = false;
//     }

// public:
//     bool checkValidString(string s)
//     {

//         int n = s.length();
//         dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
//         return check(0, s, 0, n);
//     }
// };

class Solution
{

public:
    bool checkValidString(string s)
    {
        int n = s.length();

        int mn = 0;
        int mx = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                mn++;
                mx++;
            }
            else if (s[i] == ')')
            {
                mn--;
                mx--;
            }
            else
            {
                mn--;
                mx++;
            }

            if (mn < 0)
                mn = 0;

            if (mx < 0)
                return false;
        }

        return mn == 0;
    }
};

int main()
{
    Solution sol;
    string s = "(*))"; // Sample input
    bool result = sol.checkValidString(s);
    cout << (result ? "true" : "false") << endl;
    return 0;
}
