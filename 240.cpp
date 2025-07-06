#include <iostream>
#include <vector>
using namespace std;

// Btter binary solution (brute you can do easily) (O(n) + logm)

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

// Optimal binary (O(n+m))

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0, column = m - 1;

        while(row < n && column >=0){
            if(matrix[row][column] == target){
                return true;
            }
            else if(matrix[row][column] > target){
                column--;
            }
            else{
                row++;
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};

    int target = 33;

    bool result = sol.searchMatrix(matrix, target);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
