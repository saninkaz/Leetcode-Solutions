#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        int j=0;
        while(i<n){
            if(j<n && arr[i] == 0){
                while(j<n && arr[j] == 0){
                    j++;
                }
                if(j<n) swap(arr[i],arr[j]);
                i++;
            }
            else{
                i++;
                j++;
            }
            
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12}; // Example input
    sol.moveZeroes(nums);

    // Output the result
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
