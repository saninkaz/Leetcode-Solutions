#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {

        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, -1, 0, 1};

        while (!q.empty())
        {
            int first = q.front().first;
            int second = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = first + delrow[i];
                int ncol = second + delcol[i];

                if (nrow < m && ncol < n && nrow >= 0 && ncol >= 0 && mat[nrow][ncol] == 1 && visited[nrow][ncol] == 0)
                {
                    if (!visited[nrow][ncol])
                    {
                        visited[nrow][ncol]=1;
                        mat[nrow][ncol]+= mat[first][second];
                        q.push({nrow, ncol});
                    }
                }
            }
        }

        return mat;
    }
};

int main()
{

    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}};

    Solution sol;
    vector<vector<int>> result = sol.updateMatrix(mat);

    for (const auto &row : result)
    {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
