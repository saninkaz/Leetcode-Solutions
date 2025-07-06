#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int computeBoq(vector<int> &bloomDay, int n, int days, int k)
    {
        int kd = 0;
        int bq = 0;

        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= days)
            {
                kd++;
            }
            else
            {
                kd = 0;
            }
            if (kd == k)
            {
                bq++;
                kd = 0;
            }
        }
        return bq;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {

        int n = bloomDay.size();

        int mx = INT_MIN;
        int mn = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            mx = max(bloomDay[i], mx);
            mn = min(bloomDay[i], mn);
        }

        int low = mn, high = mx;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int numberOfBouqeutes = computeBoq(bloomDay, n, mid, k);

            if (numberOfBouqeutes >= m)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        if (high != mx)
        {
            return low;
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> bloomDay = {7, 7, 7, 7, 12, 7, 7};
    int m = 2;
    int k = 3;

    int result = sol.minDays(bloomDay, m, k);
    cout << "Minimum number of days: " << result << endl;

    return 0;
}
