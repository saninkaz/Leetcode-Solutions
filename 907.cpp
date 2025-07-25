#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Brute force

// class Solution
// {
// public:
//     int sumSubarrayMins(vector<int> &arr)
//     {
//         int n = arr.size();
//         const int MOD = 1e9 + 7;
//         int total = 0;

//         for (int i = 0; i < n; i++)
//         {
//             int mn = INT_MAX;
//             for (int j = i; j < n; j++)
//             {
//                 mn = min(arr[j], mn);
//                 total = (total + mn) % MOD;
//             }
//         }

//         return total;
//     }
// };

// Optimal solution

class Solution
{
private:
    vector<int> nextSmallerElement(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> res(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (st.size() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                res[i] = n;
            }
            else
            {
                res[i] = st.top();
            }
            st.push(i);
        }

        return res;
    }

    vector<int> previousSmallerEqualToElement(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> res;
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (st.size() && arr[st.top()] > arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                res.push_back(-1);
            }
            else
            {
                res.push_back(st.top());
            }
            st.push(i);
        }

        return res;
    }

public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        int total = 0;
        vector<int> nse = nextSmallerElement(arr);
        vector<int> pse = previousSmallerEqualToElement(arr);

        for (int i = 0; i < n; i++)
        {
            int a = nse[i] - i;
            int b = i - pse[i];

            total = (total + (1LL * arr[i] * a * b) % MOD) % MOD;
        }

        return total;
    }
};

int main()
{
    Solution sol;

    // Example input
    vector<int> arr = {3, 1, 2, 4};

    // Call the function and print result
    int result = sol.sumSubarrayMins(arr);
    cout << "Sum of subarray minimums: " << result << endl;

    return 0;
}
