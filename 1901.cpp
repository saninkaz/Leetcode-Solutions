#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Optimal solution binary search (time complexity = O(logm * n))

class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int mx = INT_MIN;
            int index = 0;
            for (int i = 0; i < n; i++)
            {
                if (mat[i][mid] > mx)
                {
                    mx = mat[i][mid];
                    index = i;
                }
            }
            int left = mid - 1 >= 0 ? mat[index][mid - 1] : -1;
            int right = mid + 1 < m ? mat[index][mid + 1] : -1;
            if (mx > right && mx > left)
            {
                return {index, mid};
            }
            else if (right > mx)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return {-1, -1};
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> mat = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}};

    vector<int> peak = sol.findPeakGrid(mat);
    cout << "Peak element at: [" << peak[0] << ", " << peak[1] << "]" << endl;

    return 0;
}
