#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Brute solution time = nlogn + 2n

// class Solution
// {
// public:
//     vector<vector<int>> merge(vector<vector<int>> &intervals)
//     {

//         int n = intervals.size();
//         vector<vector<int>> result;

//         sort(intervals.begin(), intervals.end());

//         for (int i = 0; i < n; i++)
//         {
//             int start = intervals[i][0];
//             int end = intervals[i][1];

//             if (!result.empty() && end <= result.back()[1])
//             {
//                 continue;
//             }

//             for (int j = i + 1; j < n; j++)
//             {
//                 if (intervals[j][0] <= end)
//                 {
//                     end= intervals[j][1] > end ? intervals[j][1] : end;
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }

//             result.push_back({start,end});
//         }

//         return result;
//         ;
//     }
// };

// Optimal solution time = nlogn + n

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        int n = intervals.size();
        vector<vector<int>> result;

        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < n; i++)
        {
            if (result.empty() || intervals[i][0] > result.back()[1])
            {
                result.push_back({intervals[i]});
            }

            else if (intervals[i][0] <= result.back()[1] && intervals[i][1] > result.back()[1]){
                result.back()[1]= intervals[i][1];
            }
        }

        return result;
        ;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {
        {1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> mergedIntervals = sol.merge(intervals);

    cout << "Merged Intervals:" << endl;
    for (const auto &interval : mergedIntervals)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
