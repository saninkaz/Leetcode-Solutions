#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {

        int n = fruits.size();

        unordered_map<int, int> mpp;
        int maxLen = 0;
        int j = 0;
        for (int i = 0; i < n; i++)
        {

            mpp[fruits[i]]++;

            if (mpp.size() > 2)
            {
                mpp[fruits[j]]--;

                if (mpp[fruits[j]] == 0)
                {
                    mpp.erase(fruits[j]);
                }
                j++;
            }

            if (mpp.size() <= 2)
            {
                maxLen = max(maxLen, i - j + 1);
            }
        }
        return maxLen;
    }
};

int main()
{
    Solution sol;

    // Sample input
    vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};

    // Call function and print result
    int result = sol.totalFruit(fruits);
    cout << "Maximum fruits collected: " << result << endl;

    return 0;
}
