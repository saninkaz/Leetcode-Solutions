#include <iostream>
#include <vector>

using namespace std;

// Normal solution

// class Solution
// {
// public:
//     int searchInsert(vector<int> &nums, int target)
//     {

//         int n = nums.size();
//         int low = 0, high = n - 1;
//         int index = 0;
//         while (low <= high)
//         {
//             int mid = (low + high) / 2;
//             if (nums[mid] == target)
//                 return mid;
//             else if (nums[mid] > target)
//             {
//                 high = mid - 1;
//                 index = high + 1;
//             }
//             else
//             {
//                 low = mid + 1;
//                 index = low;
//             }
//         }
//         if (index == -1)
//             return 0;
//         return index;
//     }
// };

// Lower bound solution

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {

        int n = nums.size();
        int low = 0, high = n - 1;
        int index = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return index;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 3,5,6};
    int target = 7;

    int result = sol.searchInsert(nums, target);

    cout << "Index or insert position: " << result << endl;

    return 0;
}
