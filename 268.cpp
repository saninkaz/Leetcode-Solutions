#include <iostream>
#include <vector>
using namespace std;

// Solution 1 (Brute force)

// class Solution
// {
// public:
//     int missingNumber(vector<int> &nums)
//     {

//         int n = nums.size();
//         for (int i = n; i >= 0; i--)
//         {
//             int found = 0;
//             for (int j = 0; j < n; j++)
//             {
//                 if (nums[j] == i)
//                 {
//                     found = 1;
//                     break;
//                 }
//             }
//             if(found==0){
//                 return i;
//             }
//         }
//     }
// };

// Solution 2 (with time complexity O(n) and extra space complexity O(n))

// class Solution
// {
// public:
//     int missingNumber(vector<int> &nums)
//     {

//         int n = nums.size();
//         vector<int> temp(n+1);
//         for (int i = 0; i < n; i++)
//         {
//             temp[nums[i]] = 1;
//         }
//         for (int i = 0; i <=n ; i++){
//             if(temp[i]==0){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

// Solution 3 (with time complexity O(n) and extra space complexity O(1))

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {

        int n = nums.size();
        int sum=(n*(n+1))/2;
        int j=0;
        for (int i = 0; i < n; i++)
        {
            j+=nums[i];
        }
        return sum-j;
    }
};

// Solution 4 (with XOR most efficient)

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int xor1=0;
        int xor2=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            xor2=xor2^nums[i];
            xor1=xor1^i;
        }
        xor1=xor1^n;
        return xor1^xor2;
    }
};

int main()
{
    vector<int> nums = {9,6,4,2,3,5,7,0,1}; // Sample input
    Solution sol;
    int result = sol.missingNumber(nums);
    cout << "Missing number: " << result << endl;
    return 0;
}
