class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        int j = 0;

        for(int i = 0;i < n;i++){
            if(nums[i]==0){
                count += (i - j + 1);
            }
            else j=i+1;
        }

        return count;
    }
};