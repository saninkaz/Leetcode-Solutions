#include <iostream>
#include <vector>

using namespace std;

// Solution 1 (Brute force)

// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {

//         vector<int> result;
//         int n= nums.size();
//         int j=1;
//         for(int i=0;i<n;i++){
//             if(nums[i]>0){
//                 result.push_back(nums[i]);
//             }
//         }
//         for(int i=0;i<n;i++){
//             if(nums[i]<0){
//                 result.insert(result.begin()+j,nums[i]);
//                 j+=2;
//             }
//         }

//         return result;
//     }
// };

// Solution 2  (more better brute force)(time complexity - 2n) (space -n)

// class Solution
// {
// public:
//     vector<int> rearrangeArray(vector<int> &nums)
//     {

//         vector<int> result;
//         vector<int> pos;
//         vector<int> neg;
//         int n = nums.size();
//         for (int i = 0; i < n; i++)
//         {
//             if (nums[i] > 0)
//             {
//                 pos.push_back(nums[i]);
//             }
//             else
//             {
//                 neg.push_back(nums[i]);
//             }
//         }
//         for (int i = 0; i < n/2; i++)
//         {
//             result.push_back(pos[i]);
//             result.push_back(neg[i]);
//         }
//         return result;
//     }
// };

// Soltion 3 (most optimal time complexity - n, space - n)

// class Solution
// {
// public:
//     vector<int> rearrangeArray(vector<int> &nums)
//     {

//         int n = nums.size();
//         vector<int> result(n);
//         int a=0,b=1;
//         for (int i = 0; i < n; i++)
//         {
//             if (nums[i] > 0)
//             {
//                 result[a]=nums[i];
//                 a+=2;
//             }
//             else
//             {
//                 result[b]=nums[i];
//                 b+=2;
//             }
//         }
//         return result;
//     }
// };

// Solution 4 (for unequal number of positive and negative elements)

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> result;
        vector<int> pos;
        vector<int> neg;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                pos.push_back(nums[i]);
            }
            else
            {
                neg.push_back(nums[i]);
            }
        }

        int traverse = min(pos.size(), neg.size());
        for (int i = 0; i < traverse; i++)
        {
            result.push_back(pos[i]);
            result.push_back(neg[i]);
        }

        while (traverse < pos.size())
        {
            result.push_back(pos[traverse]);
            traverse++;
        }
        while (traverse < neg.size())
        {
            result.push_back(neg[traverse]);
            traverse++;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 1, -2, -5, 2, -4, 1, 2, 3,-1};

    vector<int> rearranged = sol.rearrangeArray(nums);

    for (int num : rearranged)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
