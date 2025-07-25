#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> nextGreaterElement(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> res(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (st.size() && arr[st.top()] <= arr[i])
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

    vector<int> previousGreaterEqualToElement(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> res(n);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (st.size() && arr[st.top()] < arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                res[i] = -1;
            }
            else
            {
                res[i] = st.top();
            }
            st.push(i);
        }

        return res;
    }

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
    long long subArrayRanges(vector<int> &nums)
    {
        int n = nums.size();
        long long total1 = 0;
        long long total2 = 0;
        vector<int> nse = nextSmallerElement(nums);
        vector<int> pse = previousSmallerEqualToElement(nums);
        vector<int> nge = nextGreaterElement(nums);
        vector<int> pge = previousGreaterEqualToElement(nums);

        for (int i = 0; i < n; i++)
        {
            int a = nse[i] - i;
            int b = i - pse[i];

            int p = nge[i] - i;
            int q = i - pge[i];

            total1 = total1 + (1LL * nums[i] * a * b);
            total2 = total2 + (1LL * nums[i] * p * q);
        }

        return abs(total1 - total2);
    }
};

int main()
{
    Solution sol;

    // Example input
    vector<int> nums = {1, 2, 3};

    // Call the function and print result
    long long result = sol.subArrayRanges(nums);
    cout << "Sum of subarray ranges: " << result << endl;

    return 0;
}
