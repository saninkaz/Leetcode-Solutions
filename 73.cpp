#include <iostream>
#include <vector>
using namespace std;

// Solution 1 (Brute force)

// class Solution
// {
// public:
//     void setZeroes(vector<vector<int>> &matrix)
//     {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<vector<int>> zeroes;

//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (matrix[i][j] == 0)
//                 {
//                     zeroes.push_back({i, j});
//                 }
//             }
//         }

//         for (int i = 0; i < zeroes.size(); i++)
//         {
//             for(int j=0;j<n;j++){
//                 int row = zeroes[i][0];
//                 matrix[row][j]=0;
//             }
//             for(int j=0;j<m;j++){
//                 int column = zeroes[i][1];
//                 matrix[j][column]=0;
//             }
//         }
//     }
// };

// Solution 2 (keeping track of rows and columns) (time = n x m) (space = n + m)

// class Solution
// {
// public:
//     void setZeroes(vector<vector<int>> &matrix)
//     {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<int> rows(m);
//         vector<int> columns(n);

//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (matrix[i][j] == 0)
//                 {
//                     rows[i] = 1;
//                     columns[j] = 1;
//                 }
//             }
//         }

//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (rows[i] || columns[j])
//                 {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//     }
// };

// Solution 3 (most optimal) (space = 1)

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    if (j != 0)
                    {
                        matrix[0][j] = 0;
                    }
                    else
                    {
                        col0 = 0;
                    }
                }
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[0][i] = 0;
            }
        }
        if (col0 == 0)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};

    sol.setZeroes(matrix);

    cout << "Modified Matrix:\n";
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
