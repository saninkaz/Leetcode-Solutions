#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    void rec(int i, vector<int> &nums, int n, vector<int> &temp, vector<vector<int>> &result, int sum)
    {
        result.push_back(temp);
        if (i >= n)
        {
            return;
        }

        for (int j = i; j < nums.size(); j++)
        {
            if (j > i && nums[j] == nums[j - 1])
                continue;
            temp.push_back(nums[j]);
            rec(j + 1, nums, n, temp, result, sum + nums[j]);

            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> temp = {};
        int n = nums.size();

        sort(nums.begin(), nums.end());
        rec(0, nums, n, temp, result, 0);

        return result;
    }
};

int main()
{
    Solution sol;

    // Example input
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = sol.subsetsWithDup(nums);

    // Output the result
    for (const auto &subset : result)
    {
        cout << "[";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
