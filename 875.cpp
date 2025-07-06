#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <climits>

using namespace std;

// Extreme Brute force (did not work in leetcode) (highly inefficient)

// class Solution
// {
// public:
//     int minEatingSpeed(vector<int> &piles, int h)
//     {

//         int n = piles.size();

//         int count = 0;
//         int j = 1;
//         for (int i = 0; i < n; i++)
//         {
//             int diff = piles[i];
//             while (true)
//             {

//                 if (count >= h)
//                 {
//                     j++;
//                     i = -1;
//                     count = 0;
//                     break;
//                 }

//                 diff = diff - j;

//                 count++;

//                 if (diff <= 0)
//                 {
//                     break;
//                 }
//             }
//         }

//         return j;
//     }
// };

// Solution 2 (Also time limit exceeded)

// class Solution
// {
// public:
//     int minEatingSpeed(vector<int> &piles, int h)
//     {

//         int n = piles.size();
//         int mx = INT_MIN;
//         for (int i = 0; i < n; i++)
//         {
//             if (piles[i] > mx)
//                 mx = piles[i];
//         }

//         int low = 1, high = mx;

//         while (low <= high)
//         {
//             int mid = (low + high) / 2;
//             int count = 0;
//             int i = 0;
//             int diff = piles[i];

//             while (true)
//             {

//                 if (count > h)
//                 {
//                     low = mid + 1;
//                     count = 0;
//                     break;
//                 }

//                 diff = diff - mid;
//                 count++;

//                 if (diff <= 0)
//                 {
//                     if (count > h)
//                     {
//                         low = mid + 1;
//                         count = 0;
//                         break;
//                     }
//                     if (i == n - 1)
//                     {
//                         break;
//                     }
//                     diff = piles[++i];
//                 }
//             }
//             if (count <= h && count != 0)
//             {
//                 mx = mid;
//                 high = mid - 1;
//             }
//         }
//         return mx;
//     }
// };

// Solution 3

class Solution
{
public:
    long long computeTime(vector<int> &piles, int mid, int h)
    {

        long long time = 0;

        for (int i = 0; i < piles.size(); i++)
        {
            long long hours = piles[i] / mid;
            time += piles[i] % mid == 0 ? hours : hours + 1;
            if (time > h)
            {
                return time;
            }
        }

        return time;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {

        int n = piles.size();
        int mx = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (piles[i] > mx)
                mx = piles[i];
        }

        int low = 1, high = mx;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int requiredTime = computeTime(piles, mid, h);

            if (requiredTime > h)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main()
{
    Solution sol;

    vector<int> piles = {30, 11, 23, 4, 20};
    int h = 5;

    int result = sol.minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << result << endl;

    return 0;
}
