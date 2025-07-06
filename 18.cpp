#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute force and better solution is same as twosum and threesum

// Optimal solution

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;

        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;


            for (int j = i + 1; j < n; j++)
            {

                if (j > 0 && nums[j] == nums[j - 1] && j-1!=i)
                    continue;

                int k = j + 1, l = n - 1;

                while (k < l)
                {
                    long long sum = nums[i] + nums[j];

                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target)
                    {
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while( k<l && nums[k]==nums[k-1]){
                            k++;
                        }
                        while( k<l && nums[l]==nums[l+1]){
                            l--;
                        }
                    }
                    else if(sum < target){
                        k++;
                    }
                    else if(sum > target){
                        l--;
                    }
                    
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {2,2,2,2,2};
    int target = 8;

    vector<vector<int>> result = sol.fourSum(nums, target);

    for (const auto &quad : result)
    {
        for (int num : quad)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
