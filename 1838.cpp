#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());
        long long l=0;
        long long r=0;
        long long len=r-l+1;
        long long sum=0;
        long long frequency=0;
        while(r<=nums.size()-1){
            sum=sum+nums[r];

            if((nums[r]*len)<=sum+k){
                frequency=max(frequency,len);
                r++;
            }
            else{
                sum=sum-nums[l];
                l++; 
                r++;               
            }
            len=r-l+1;
                
        }
        return frequency;
    }   
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,4}; // Example input
    int k = 5;
    
    cout << "Maximum frequency after at most " << k << " operations: " 
         << sol.maxFrequency(nums, k) << endl;
    
    return 0;
}
