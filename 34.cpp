#include <iostream>
#include <vector>

using namespace std;

// Solution 1 using only lower bound (also without stl lower bound function, implemented it directly)

// class Solution
// {
// public:
//     vector<int> searchRange(vector<int> &nums, int target)
//     {
//         int n = nums.size();

//         vector<int> result;

//         int low = 0, high = n - 1;
//         int ans = n;

//         while (low <= high)
//         {
//             int mid = (low + high) / 2;
//             if (nums[mid] >= target)
//             {
//                 ans = mid;
//                 high = mid - 1;
//             }
//             else
//             {
//                 low = mid + 1;
//             }
//         }

//         if (ans < n && nums[ans] == target)
//         {

//             result.push_back(ans);

//             while (ans < n && nums[ans] == target)
//             {
//                 ans++;
//             }

//             result.push_back(ans - 1);
//         }

//         if (result.empty())
//         {
//             return {-1, -1};
//         }

//         return result;
//     }
// };

// Solution 2 using lower bound and upper bound

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();

        vector<int> result;

        int lw = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        int low = 0, high = n - 1;
        int up = n;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] > target)
            {
                up = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        if (lw < n && nums[lw] == target)
        {
            result.push_back(lw);
            result.push_back(up - 1);
            return result;
        }

        return {-1, -1};
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 7;

    vector<int> result = sol.searchRange(nums, target);

    cout << "Start and end positions: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
