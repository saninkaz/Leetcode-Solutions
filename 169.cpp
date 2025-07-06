#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// Solution 1 (brute force)

// class Solution {
// public:
//     int majorityElement(vector<int>& arr) {
//         int n=arr.size();
//         int count=0;
//         int mx=0;
//         int ans=0;
//         for(int i=0;i<n;i++){
//             count=0;
//             for(int j=i;j<n;j++){
//                 if(arr[i]==arr[j]){
//                     count++;
//                 }
//             }
//             if(count>mx){
//                 mx=count;
//                 ans=arr[i];
//             }
//         }
//         return ans;
//     }
// };

// Solution 2  (using hashmap) (time complexity = nlogn) (space complexity = n)

// class Solution {
// public:
//     int majorityElement(vector<int>& arr) {
//         int n=arr.size();
//         map<int,int> hash;
//         for(int i=0;i<n;i++){
//             hash[arr[i]]++;
//         }
//         for(int i=0;i<n;i++){
//             if(hash[arr[i]] > n/2){
//                 return arr[i];
//             }
//         }
//         return 0;
//     }
// };

// Optimal solution

class Solution
{
public:
    int majorityElement(vector<int> &arr)
    {
        int n = arr.size();
        int me = arr[0];
        int count = 1;
        for (int i = 1; i < n; i++)
        {
            if (count == 0)
            {
                me = arr[i];
                count++;
                continue;
            }
            if (arr[i] == me)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == me)
            {
                count++;
            }
        }
        if (count > n / 2)
        {
            return me;
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 2, 1, 1, 1, 1, 1, 2, 2};

    int result = sol.majorityElement(nums);
    cout << "Majority element: " << result << endl;

    return 0;
}
