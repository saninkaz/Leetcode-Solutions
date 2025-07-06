#include <iostream>
#include <vector>
using namespace std;

// Solution 1 (Iterative)

// class Solution
// {
// public:
//     int search(vector<int> &nums, int target)
//     {

//         int n = nums.size();
//         int low = 0, high = n - 1;
//         while (low <= high)
//         {
//             int mid = (low + high) / 2;
//             if (nums[mid] == target)
//                 return mid;
//             else if (nums[mid] > target)
//                 high = mid - 1;
//             else
//             {
//                 low = mid + 1;
//             }
//         }
//         return -1;
//     }
// };

// Solution 2 (Recursive)

class Solution
{
public:

    int binarySearch(vector<int> &nums,int target,int low,int high){
        int n = nums.size();
        if(low <=high){
            int mid = (low + high)/2;
            if(nums[mid]== target) return mid;
            else if(nums[mid]>target) return binarySearch(nums,target,low,mid-1);
            else{
                return binarySearch(nums,target,mid+1,high);
            }
        }
        return -1; 
    }

    int search(vector<int> &nums, int target)
    {

        int n = nums.size();
        return binarySearch(nums,target,0,n-1);
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {-1, 0, 3, 5, 9, 12}; // Example input
    int target = 9;

    int result = sol.search(nums, target);
    cout << "Index of target: " << result << endl;

    return 0;
}
