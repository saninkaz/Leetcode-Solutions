#include <iostream>
#include <vector>
#include <climits>
#include <bits/stdc++.h>

using namespace std;

// Solution 1 (Brute force) (Time limit exceeded in leetcode)

// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         int n = prices.size();
//         int mx = INT_MIN;
//         int profit = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = i + 1; j < n; j++)
//             {
//                 profit = prices[j] - prices[i];
//                 mx=max(profit,mx);
//             }
//         }
//         if(mx>0){
//             return mx;
//         }
//         else{
//             return 0;
//         }
//     }
// };

// Solution 2

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int mx = INT_MIN;
        int profit = 0;
        int mn = prices[0];
        for(int i=1;i<n;i++){
            profit = prices[i]- mn;
            mx= max(profit,mx);
            mn = min(prices[i],mn);
        }
        if(mx>0){
            return mx;
        }
        else{
            return 0;
        }
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int result = sol.maxProfit(prices);
    cout << "Maximum profit: " << result << endl;

    return 0;
}
