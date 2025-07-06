#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int min= nums[0];
        int change=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1] && change==0){
                change=1;
                if(nums[i]>nums[0] && change==1){
                return false;
                }
                continue;
                }
            if(nums[i]>nums[0] && change==1){
                return false;
                }
            if(nums[i]<nums[i-1] && change==1){
                return false;
                }
          
        }
          return true;
    }    
};

int main() {
    Solution sol;
    
    vector<int> nums = {3, 4, 5, 1, 2};  // Example input
    bool result = sol.check(nums);
    
    cout << (result ? "true" : "false") << endl;

    return 0;
}
