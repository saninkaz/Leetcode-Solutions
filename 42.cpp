#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();

        vector<int> prefixMax(n, 0);
        vector<int> suffixMax(n, 0);

        prefixMax[0] = height[0];
        suffixMax[n-1] = height[n - 1];

        for (int i = 1; i < n; i++)
        {
            prefixMax[i] = max(height[i], prefixMax[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            suffixMax[i] = max(height[i], suffixMax[i + 1]);
        }

        int res = 0;

        for (int i = 0; i < n; i++)
        {
            int pm = prefixMax[i];
            int sm = suffixMax[i];
            if (height[i] < pm && height[i] < sm)
            {
                res += min(pm, sm) - height[i];
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;

    // Example input
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    // Call the function and print result
    int result = sol.trap(height);
    cout << "Trapped rain water: " << result << endl;

    return 0;
}
