#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {

        int n = intervals.size();

        int low = 0;
        int high = 0;
        int count = 0;

        sort(intervals.begin(), intervals.end(), cmp);

        low = intervals[0][0];
        high = intervals[0][1];

        for (int i = 1; i < n; i++)
        {
            int l = intervals[i][0];
            int h = intervals[i][1];

            if (l >= high)
            {
                high = h;
                continue;
            }
            count++;
        }

        return count;
    }
};

int main()
{
    Solution sol;

    // Example usage
    vector<vector<int>> intervals = {{1, 100}, {11, 22}, {1, 11}, {2, 12}};

    int result = sol.eraseOverlapIntervals(intervals);
    cout << "Minimum number of intervals to remove: " << result << endl;

    return 0;
}
