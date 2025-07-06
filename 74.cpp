#include <iostream>
#include <vector>
using namespace std;

// Binary search normal O(n*logm)

// class Solution
// {
// public:
//     bool searchMatrix(vector<vector<int>> &matrix, int target)
//     {
//         int n = matrix.size();
//         int m = matrix[0].size();

//         for (int i = 0; i < n; i++)
//         {
//             int low = 0, high = m - 1;
//             while (low <= high)
//             {
//                 int mid = (low + high) / 2;
//                 if (matrix[i][mid] == target)
//                 {
//                     return true;
//                 }
//                 if (matrix[i][mid] > target)
//                 {
//                     high = mid - 1;
//                 }
//                 else
//                 {
//                     low = mid + 1;
//                 }
//             }
//         }
//         return false;
//     }
// };

// Better binary O(n) + log(m)

// class Solution
// {
// public:
//     bool searchMatrix(vector<vector<int>> &matrix, int target)
//     {
//         int n = matrix.size();
//         int m = matrix[0].size();

//         for (int i = 0; i < n; i++)
//         {
//             if (matrix[i][0] <= target && target <= matrix[i][m - 1])
//             {
//                 int low = 0, high = m - 1;
//                 while (low <= high)
//                 {
//                     int mid = (low + high) / 2;
//                     if (matrix[i][mid] == target)
//                     {
//                         return true;
//                     }
//                     if (matrix[i][mid] > target)
//                     {
//                         high = mid - 1;
//                     }
//                     else
//                     {
//                         low = mid + 1;
//                     }
//                 }
//             }
//         }
//         return false;
//     }
// };

// Most optimal binary (O(log n*m))

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0, high = (m * n) - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int row = mid / m;
            int column = mid % m;
            if (matrix[row][column] == target)
            {
                return true;
            }
            else if (matrix[row][column] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};
    int target = 22;

    bool result = sol.searchMatrix(matrix, target);
    cout << result;

    return 0;
}
