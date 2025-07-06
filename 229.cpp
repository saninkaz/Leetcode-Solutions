#include <iostream>
#include <vector>

using namespace std;

// Solution 1 (optimal)  (note that brute and better can be done in tha same way as problem no 169)

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> result;

        int mg1, mg2;
        int count1 = 0, count2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (count1 == 0 && nums[i] !=mg2)
            {
                mg1 = nums[i];
            }
            else if (count2 == 0 && nums[i]!=mg1) 
            {
                mg2 = nums[i];
            }
            if (nums[i] == mg1)
            {
                count1++;
            }
            else if (nums[i] == mg2)
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == mg1)
            {
                count1++;
            }
            else if (nums[i] == mg2)
            {
                count2++;
            }
        }

        if (count1 > n / 3)
        {
            result.push_back(mg1);
        }

        if (count2 > n / 3)
        {
            result.push_back(mg2);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3,2,3}; // Example input
    vector<int> result = sol.majorityElement(nums);

    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
