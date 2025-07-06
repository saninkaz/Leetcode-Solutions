#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void rec(int i, vector<int> &candidates, int n, int target, vector<int> &temp, vector<vector<int>> &result)
    {
        if(target == 0){
            result.push_back(temp);
            return;
        }

        for(int j=i;j<candidates.size();j++){
            if(j>i && candidates[j]==candidates[j-1]) continue;
            if(candidates[j]> target){
                break;
            }
            temp.push_back(candidates[j]);
            rec(j+1,candidates,n,target-candidates[j],temp,result);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> temp = {};

        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        rec(0, candidates, n, target, temp, result);

        return result;
    }
};

int main()
{
    Solution sol;

    // Example input
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> result = sol.combinationSum2(candidates, target);

    // Output the result
    for (const auto &combo : result)
    {
        cout << "[";
        for (int num : combo)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
