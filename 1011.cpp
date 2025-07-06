#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int computeDays(vector<int> &weights, int n, int shipWeight)
    {
        int days = 1;
        int totalWeight = 0;
        for (int i = 0; i < n; i++)
        {
            totalWeight += weights[i];
            if (totalWeight > shipWeight)
            {
                totalWeight = weights[i];
                days++;
            }
        }
        return days;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {

        int n = weights.size();

        int mx = 0;
        int mn = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            mx += weights[i];
            mn = max(weights[i], mn);
        }

        int low = mn, high = mx;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            int computedDays = computeDays(weights, n, mid);
            if (computedDays > days)
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

    vector<int> weights = {1, 2, 3, 1, 1};
    int days = 4;

    int result = sol.shipWithinDays(weights, days);
    cout << "Minimum ship capacity: " << result << endl;

    return 0;
}
