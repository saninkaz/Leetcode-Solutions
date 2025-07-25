#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        

    int n = arr.size();
    int avg =0;
    int count =0;
    if(threshold == 0){
        return n +1-k;
    }

    int sum =0;
    
    for(int i=0;i<n;i++){
        sum+= arr[i];
        if((i>=k-1)){
            if((sum/k)>=threshold){
                count++;
            }
            sum-=arr[i-k+1];
        }
    }

    return count;
    }
};

int main() {
    Solution sol;
    
    vector<int> arr = {2, 2, 2, 2, 5, 5, 5, 8};
    int k = 3;
    int threshold = 4;

    int result = sol.numOfSubarrays(arr, k, threshold);
    cout << "Result: " << result << endl;

    return 0;
}
