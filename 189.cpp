#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Solution 1 (Brute force) ( Time limit exceeded for leetcode)

// class Solution {
// public:
//     void rotate(vector<int>& arr, int k) {
//         int n=arr.size();
//         int rotations= (k%n);
//         for(int i=1;i<=rotations;i++){
//             int last=arr[n-1];
//             for(int j=n-1;j>=1;j--){
//                 arr[j]=arr[j-1];
//             }
//             arr[0]=last;
//     }
//     }
// };


// Solution 2 (Takes extra space complexity of O[n])

// class Solution {
// public:
//     void rotate(vector<int>& arr, int k) {
//         int n=arr.size();
//         int rotations= n-(k%n);
//         vector<int> temp;
//         for(int i=0;i<rotations;i++){
//             cout <<arr[i];
//             temp.push_back(arr[i]);
//         }
//         for(int i=0;i<=n-1-rotations;i++){
//             arr[i]=arr[i+rotations];
//         }
//         int j=0;
//         for(int i=n-rotations;i<n;i++){
//             arr[i]=temp[j];
//             j++;
//         }
          
//     }
// };  

// Solution 3 (Takes no extra space complexity)

class Solution {
public:
    void rotate(vector<int>& arr, int k) {

        int n=arr.size();
        int rotations = n-(k%n);
        
        reverse(arr.begin(),arr.begin()+rotations);
        reverse(arr.begin()+rotations,arr.end());
        reverse(arr.begin(),arr.end());
    }
};  




int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4}; // Example input
    int k = 2;

    sol.rotate(nums, k); // Function call

    // Output the rotated array
    cout << "Rotated array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
