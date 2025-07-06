#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int unique=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]!=arr[i-1]){
                arr[unique]=arr[i];
                unique++;
            }
        }
        return unique;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};  // Example input
    int k = sol.removeDuplicates(nums);       // Function call

    // Print the result
    cout << "k = " << k << endl;
    cout << "Modified array: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
