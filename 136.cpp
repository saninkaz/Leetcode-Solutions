#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Solution 1 (Brute force)

// class Solution
// {
// public:
//     int singleNumber(vector<int> &nums)
//     {
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             int element=nums[i];
//             int count=0;
//             for(int j=0;j<n;j++){
//                 if(element==nums[j]){
//                     count++;
//                 }
//             }
//             if(count==1) return element;
//         }
//         return -1;
//     }
// };

// Solution 2 (Optimal)

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        int xor1=0;
        for(int i=0;i<n;i++){
            xor1=xor1^nums[i];
        }
        return xor1;
    }
};



int main()
{
    vector<int> nums = {2,2,1}; // Sample input

    Solution sol;
    int result = sol.singleNumber(nums);

    cout << "Single number is: " << result << endl;

    return 0;
}
