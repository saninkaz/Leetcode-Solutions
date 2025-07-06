#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int maxCount=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                count++;
            }
            else if(nums[i]==0){
                maxCount=max(maxCount,count);
                count=0;
            }
        }
        maxCount=max(maxCount,count);
        return maxCount;
    }
};

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1}; // Sample input

    Solution sol;
    int result = sol.findMaxConsecutiveOnes(nums);

    cout << "Maximum consecutive 1s: " << result << endl;

    return 0;
}
