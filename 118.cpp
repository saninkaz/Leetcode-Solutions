#include <iostream>
#include <vector>
using namespace std;

// Solution 1 (Brute force)

// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> triangle;

//         triangle.push_back({1});

//         int start=1;

//         if(numRows==1){
//             return triangle;
//         }

//         triangle.push_back({1,1});

//         if(numRows==2){
//             return triangle;
//         }

//         for(int i=3;i<=numRows;i++){

//             vector<int> last=triangle.back();

//             vector<int> push;

//             push.push_back(1);

//             for(int i=0;i<last.size()-1;i++){
//                 push.push_back(last[i]+last[i+1]);
//             }

//             push.push_back(1);

//             triangle.push_back(push);
//         }

//         return triangle;
//     }
// };

// Solution 2

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> triangle;

        for (int j = 1; j <= numRows; j++)
        {

            vector<int> push;
            int start = 1;

            push.push_back(start);

            for (int i = 1; i < j; i++)
            {
                start = start * (j - i);
                start = start / i;
                push.push_back((start));
            }
            triangle.push_back(push);
        }

        return triangle;
    }
};

int main()
{
    Solution sol;
    int numRows = 3;

    vector<vector<int>> result = sol.generate(numRows);

    for (const auto &row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
