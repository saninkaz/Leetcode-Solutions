#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> result;

        int n = intervals.size();
        int i = 0;

        while (i < n && intervals[i][1] < newInterval[0])
        {
            result.push_back(intervals[i]);
            i++;
        }
        int mn = newInterval[0];
        int mx = newInterval[1];
        while (i < n && intervals[i][0] <= mx)
        {
            mn = min(intervals[i][0], mn);
            mx = max(intervals[i][1], mx);
            i++;
        }

        result.push_back({mn, mx});

        while (i < n)
        {
            result.push_back(intervals[i]);
            i++;
            continue;
        }
        return result;
    }
};

int main()
{
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    cout << "Enter the intervals (start end):\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<int> newInterval(2);
    cout << "Enter the new interval (start end): ";
    cin >> newInterval[0] >> newInterval[1];

    Solution sol;
    vector<vector<int>> result = sol.insert(intervals, newInterval);

    cout << "Resulting intervals:\n";
    for (auto &interval : result)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "]\n";
    }

    return 0;
}
