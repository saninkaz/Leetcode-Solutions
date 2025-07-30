#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {

        int n = nums.size();
        vector<int> result;
        deque<int> q;
        int mx = nums[0];
        if (n == 1)
        {
            return nums;
        }

        for (int i = 0; i < n; i++)
        {
            while (q.size() && nums[q.back()] < nums[i])
            {
                q.pop_back();
            }
            q.push_back(i);

            if (!q.empty() && q.front() < i - k + 1)
            {
                q.pop_front();
            }
            unordered_map<int,int> mpp;

            if (i + 1 >= k)
            {
                result.push_back(nums[q.front()]);
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, -1};
    int k = 1;

    vector<int> result = sol.maxSlidingWindow(nums, k);

    cout << "Result: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
