#include <iostream>
#include <vector>

using namespace std;

// Solution 1 (Did not work in leetcode , soltion inferred from count inversions problem in takeuforward)

// class Solution
// {
// public:
//     int merge(vector<int> &nums, int low, int mid, int end)
//     {
//         vector<int> temp;
//         int left = low;
//         int right = mid + 1;
//         int count = 0;

//         while (left <= mid && right <= end)
//         {
//             if (nums[left] <= nums[right])
//             {
//                 int index = right;
//                 while (index <= end)
//                 {
//                     if ((long long)nums[left] > 2LL * nums[index])
//                     {
//                         count += 1;
//                     }
//                     index++;
//                 }

//                 temp.push_back(nums[left]);
//                 left++;
//             }
//             else
//             {
//                 int index = left;
//                 while (index <= mid)
//                 {
//                     if ((long long)nums[index] > 2LL * nums[right])
//                     {
//                         count += 1;
//                     }
//                     index++;
//                 }
//                 temp.push_back(nums[right]);
//                 right++;
//             }
//         }

//         while (left <= mid)
//         {
//             temp.push_back(nums[left]);
//             left++;
//         }

//         while (right <= end)
//         {
//             temp.push_back(nums[right]);
//             right++;
//         }

//         for (int i = low; i <= end; i++)
//         {
//             nums[i] = temp[i - low];
//         }

//         return count;
//     }

//     int mergeSort(vector<int> &nums, int low, int end)
//     {
//         int count = 0;
//         if (low < end)
//         {
//             int mid = (low + end) / 2;
//             count += mergeSort(nums, low, mid);
//             count += mergeSort(nums, mid + 1, end);
//             count += merge(nums, low, mid, end);
//             return count;
//         }
//         return count;
//     }

//     int reversePairs(vector<int> &nums)
//     {
//         int n = nums.size();
//         int count = 0;
//         count = mergeSort(nums, 0, n - 1);
//         return count;
//     }
// };

// Solution 2 works in leetcode

class Solution
{
public:
    int merge(vector<int> &nums, int low, int mid, int end)
    {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        int count = 0;
        int j = mid + 1;

        for (int i = low; i <= mid; i++)
        {
            while (j <= end && (long long)nums[i] > 2LL * nums[j])
            {
                j++;
            }
            count += (j - (mid + 1));
        }

        while (left <= mid && right <= end)
        {
            if (nums[left] <= nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= end)
        {
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = low; i <= end; i++)
        {
            nums[i] = temp[i - low];
        }

        return count;
    }

    int mergeSort(vector<int> &nums, int low, int end)
    {
        int count = 0;
        if (low < end)
        {
            int mid = (low + end) / 2;
            count += mergeSort(nums, low, mid);
            count += mergeSort(nums, mid + 1, end);
            count += merge(nums, low, mid, end);
            return count;
        }
        return count;
    }

    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;
        count = mergeSort(nums, 0, n - 1);
        return count;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 1, -1, -1, -1, 1};

    int result = sol.reversePairs(nums);

    cout << "Number of reverse pairs: " << result << endl;

    return 0;
}
