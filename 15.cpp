#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Solution 1 (Bruteforce)

// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {

//         vector<vector<int>> result;

//         int n = nums.size();

//         vector<int> push;

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = i + 1; j < n; j++)
//             {
//                 for (int k = j + 1; k < n; k++)
//                 {
//                     if (nums[i] + nums[j] + nums[k] == 0)
//                     {
//                         push = {nums[i], nums[j], nums[k]};

//                         sort(push.begin(), push.end());

//                         if (find(result.begin(), result.end(), push) == result.end())
//                         {
//                             result.push_back(push);
//                         }
//                     }
//                 }
//             }
//         }
//         return result;
//     }
// };

// Solution 2 (time limit exceeded in leetcode)

// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {

//         vector<vector<int>> result;

//         int n = nums.size();

//         unordered_map<int, int> hash;

//         for (int i = 0; i < n; i++)
//         {
//             hash[nums[i]] = i;
//         }

//         vector<int> push;

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = i + 1; j < n; j++)
//             {
//                 int toFind = -(nums[i] + nums[j]);
//                 if (hash.find(toFind) != hash.end() && hash[toFind] !=i && hash[toFind] !=j)
//                 {
//                     push = {nums[i], nums[j], toFind};

//                     sort(push.begin(), push.end());

//                     if (find(result.begin(), result.end(), push) == result.end())
//                     {
//                         result.push_back(push);
//                     }
//                 }
//             }
//         }
//         return result;
//     }
// };

// Alternate solution with set (accepted in leetcode)

// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {

//         set<vector<int>> resultset;

//         int n = nums.size();

//         unordered_map<int, int> hash;

//         for (int i = 0; i < n; i++)
//         {
//             hash[nums[i]] = i;
//         }

//         vector<int> push;

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = i + 1; j < n; j++)
//             {
//                 int toFind = -(nums[i] + nums[j]);
//                 if (hash.find(toFind) != hash.end() && hash[toFind] != i && hash[toFind] != j)
//                 {
//                     push = {nums[i], nums[j], toFind};

//                     sort(push.begin(), push.end());
//                     resultset.insert(push);
//                 }
//             }
//         }

//         vector<vector<int>> result(resultset.begin(),resultset.end());

//         return result;
//     }
// };

// Alternate solution with hashing (but time limit exceeeded)

// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {

//         set<vector<int>> resultset;

//         int n = nums.size();

//         vector<int> push;

//         for (int i = 0; i < n; i++)
//         {
//             unordered_map<int, int> hash;
//             for (int j = i + 1; j < n; j++)
//             {
//                 int toFind = -(nums[i] + nums[j]);
//                 if (hash.find(toFind) != hash.end())
//                 {
//                     push = {nums[i], nums[j], toFind};

//                     sort(push.begin(), push.end());
//                     resultset.insert(push);
//                 }
//                 hash[nums[j]]=j;
//             }
//         }

//         vector<vector<int>> result(resultset.begin(),resultset.end());

//         return result;
//     }
// };

// Optimal solution (extension of 2sum optimal solution)

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        int n = nums.size();

        vector<vector<int>> result;

        sort(nums.begin(),nums.end());

        for (int target = 0; target < n; target++)
        {
            if(target >0 && nums[target]==nums[target-1]) continue;
            int i=target+1,j=n-1;
            
            while(i<j){
                int sum=nums[i]+nums[j];
                if(sum == -(nums[target])){
                    result.push_back({nums[i],nums[j],nums[target]});
                    i++;
                    j--;
                    while(i<j && nums[i]==nums[i-1]){
                        i++;
                    }
                    while(i<j && nums[j]==nums[j+1]){
                        j--;
                    }
                }
               else if(sum < -(nums[target])){
                   i++;
                }
                else{
                    j--;
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-2,-2,-2,-1,-1,-1,0,0,0,2,2,2,2}; // Example input
    vector<vector<int>> result = sol.threeSum(nums);

    for (const auto &triplet : result)
    {
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
