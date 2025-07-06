#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int mid, int row, int col, vector<vector<int>> &grid,int n,int m,vector<vector<int>> &vis)
    {
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        vis[row][col]=1;

        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol] <=mid && !vis[nrow][ncol]){
                dfs(mid,nrow,ncol,grid,n,m,vis);
            }
        }
    }

public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int low = 0;
        int high = 50 * 50;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            vector<vector<int>> vis(n, vector<int>(m, 0));
            if(grid[0][0] <= mid)
            dfs(mid, 0, 0, grid,n,m,vis);
            if (vis[n - 1][n - 1])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {
        {0, 2},
        {1, 3}};

    cout << sol.swimInWater(grid) << endl;

    return 0;
}
