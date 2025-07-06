#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Solution 1 (Brute force)

// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int m= matrix.size();
//         int n= matrix[0].size();

//         vector<vector<int>> result(m,vector<int>(n,0));

//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 result[j][n-1-i]=matrix[i][j];
//             }
//         }
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 matrix[i][j]=result[i][j];
//             }
//         }
//     }
// };

// Solution 2 (Optimal)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n= matrix[0].size();

        for(int i=0;i<m;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    sol.rotate(matrix);

    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
