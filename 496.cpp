#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        stack<int> st;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> res;
        unordered_map<int, int> mpp;907

        for (int i = n2 - 1; i >= 0; i--)
        {

            while (st.size() && nums2[i] > st.top())
            {
                st.pop();
            }

            if (st.empty())
            {
                mpp[nums2[i]] = -1;
                st.push(nums2[i]);
            }

            else
            {
                mpp[nums2[i]] = st.top();
                st.push(nums2[i]);
            }
        }

        for (auto num : nums1)
        {
            res.push_back(mpp[num]);
        }

        return res;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    cout << "Output: [";
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i];
        if (i != result.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
