#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;

        for (int i = ((2 * n) - 1); i >= 0; i--)
        {
            while (st.size() && st.top() <= nums[i % n])
            {
                st.pop();
            };

            if (st.empty())
            {
                if (i < n)
                    res[i] = -1;
            }
            else
            {
                if (i < n)
                {
                    res[i] = st.top();
                }
            }
            st.push(nums[i%n]);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 1}; // sample input
    vector<int> result = sol.nextGreaterElements(nums);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
