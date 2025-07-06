#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// normal solution (linear search)

// class Solution
// {
// public:
//     int findKthPositive(vector<int> &arr, int k)
//     {

//         int n = arr.size();
//         int kd = 0;
//         int mx = INT_MIN;

//         for (int i = 0; i < n; i++)
//         {
//             mx = max(arr[i], mx);
//         }

//         int j = 0;
//         for (int i = 1; i <= mx; i++)
//         {
//             if (arr[j] != i)
//             {
//                 kd++;
//             }
//             else
//             {
//                 j++;
//             }
//             if (kd == k)
//             {
//                 return i;
//             }
//         }

//         return mx + k - kd;

//         return -1;
//     }
// };

// Most optimal brute force (Linear search)

// class Solution
// {
// public:
//     int findKthPositive(vector<int> &arr, int k)
//     {

//         int n = arr.size();
//         for(int i=0;i<n;i++){
//             if(arr[i]<=k) k++;
//         }
//         return k;
//     }
// };

// Binary search solution

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {

        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return k + high + 1; // (or low + k) (because low=high+1) (reference youtube video for more understanding)
    }
};

int main()
{
    Solution sol;

    vector<int> arr = {5, 6, 7, 8, 9};
    int k = 9;

    int result = sol.findKthPositive(arr, k);
    cout << "The " << k << "th missing number is: " << result << endl;

    return 0;
}
