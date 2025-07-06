#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

// Bruteforce solution

// class Solution {
// public:
//     vector<int> twoSum(std::vector<int>& nums, int target) {
//         vector<int> ans;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(nums[i]+nums[j]==target){
//                     ans.push_back(i);
//                     ans.push_back(j);
//                     return ans;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// Solution with time complexity nlogn and space complexity n (use unordermap in leetcode for better time complexity)

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> ans;
//         int n=nums.size();
//         map<int,int> hash;
//         for(int i=0;i<n;i++){
//             if(hash.find(target-nums[i]) != hash.end()){
//                 ans.push_back(i);
//                 ans.push_back(hash[target-nums[i]]);
//                 return ans;
//             }
//             else{
//                 hash[nums[i]]=i;
//             }
//         }
//         return ans;
//     }
// };

// Optimal solution only works for yes or no , does not return index , time complexity = O(nlogn), space= O(1)

class Solution
{
public:
    int twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        map<int, int> hash;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            hash[nums[i]] = i;
        }
        sort(nums.begin(), nums.end());
        int i = 0, j = n - 1;
        while (i < n && j >= 0)
        {
            if (nums[i] + nums[j] == target)
            {
                return 1;
            }
            else if (nums[i] + nums[j] <= target)
            {
                i++;
            }
            if (nums[i] + nums[j] >= target)
            {
                j--;
            }
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    int result = sol.twoSum(nums, target);

    
    cout << result << endl;

    return 0;
}
