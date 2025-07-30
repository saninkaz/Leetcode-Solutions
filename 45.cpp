#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0;
        int h = 0;
        int count = 0;

        while (h < n-1)
        {
            int far = 0;

            for (int i = l; i<= h; i++)
            {
                far = max(i + nums[i], far);
            }
            l = h + 1;
            h = far;
            count++;
        }

        return count;
    }
};

int main()
{
    Solution sol;

    // Example usage
    vector<int> nums = {2, 3, 0, 1, 4};

    int result = sol.jump(nums);
    cout << "Minimum number of jumps: " << result << endl;

    return 0;
}
