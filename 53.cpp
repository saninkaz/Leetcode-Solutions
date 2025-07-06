#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Solution 1 (Brute force) (time limit exceeeded in leetcode)

// class Solution {
// public:
//     int maxSubArray(vector<int>& arr) {
//        int sum=0;
//        int mx=INT_MIN;
//        int n=arr.size();
//        for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             int k=i;
//             while(k<=j){
//                 sum+=arr[k];
//                 k++;
//             }
//             mx=max(sum,mx);
//             sum=0;
//         }
//        }
//        return mx;
//     }
// };

// Solution 2 (brute force) (better than solution 1) (also time limit exceeeded in leetcode)

// class Solution {
// public:
//     int maxSubArray(vector<int>& arr) {
//        int sum=0;
//        int mx=INT_MIN;
//        int n=arr.size();
//        for(int i=0;i<n;i++){
//         sum=0;
//         for(int j=i;j<n;j++){
//             sum+=arr[j];
//             mx=max(sum,mx);
//         }
//        }
//        return mx;
//     }
// };

// Solution 3 (Kadane's Algorithm) (most optimal)

// class Solution {
// public:
//     int maxSubArray(vector<int>& arr) {
//        int sum=0;
//        int mx=INT_MIN;
//        int n=arr.size();
//        for(int i=0;i<n;i++){
//         sum+=arr[i];
//         mx=max(sum,mx);
//         if(sum<0){
//             sum=0;
//             continue;
//         }
//        }
//        return mx;
//     }
// };

// Additional Solution (Printing the subarrays with the maximum sum)

// class Solution
// {
// public:
//     void maxSubArray(vector<int> &arr)
//     {
//         int sum = 0;
//         int dub_sum=0;
//         int j=0;
//         int mx = INT_MIN;
//         int n = arr.size();
//         for (int i = 0; i < n; i++)
//         {
//             sum += arr[i];
//             if (sum > mx)
//             {
//                 dub_sum = sum;
//                 j = i;
//                 mx = sum;
//             }
//             if (sum < 0)
//             {
//                 sum = 0;
//                 continue;
//             }
//         }
//         vector<int> arr2;
//         while (dub_sum > 0)
//         {
//             dub_sum -= arr[j];
//             arr2.insert(arr2.begin(),arr[j]);
//             j--;
//         }
//         for(auto it: arr2){
//             cout << it << " ";
//         }
//     }
// };

// OR

class Solution
{
public:
    void maxSubArray(vector<int> &arr)
    {
        int sum = 0;
        int start = 0;
        int a_start = 0;
        int a_end = 0;
        int mx = INT_MIN;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (sum == 0)
            {
                start = i;
            }
            sum += arr[i];
            if (sum > mx)
            {
                mx = sum;
                a_start = start;
                a_end = i;
            }
            if (sum < 0)
            {
                sum = 0;
                continue;
            }
        }
        for (int j = a_start; j <= a_end; j++)
        {
            cout << arr[j] << " ";
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5, 4, -1, 7, 8};

    sol.maxSubArray(nums);

    return 0;
}
