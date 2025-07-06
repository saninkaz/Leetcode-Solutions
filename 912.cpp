#include <iostream>
#include <vector>
using namespace std;


// Merge Sort

// class Solution {
// public:

//     void merge(vector<int>& nums,int low,int mid,int high){
//         vector<int> temp;
//         int left=low;
//         int right=mid+1;
//         while(left<=mid && right<=high){
//             if(nums[left]<nums[right]){
//                 temp.push_back(nums[left]);
//                 left++;
//             }
//             else{
//                 temp.push_back(nums[right]);
//                 right++;
//             }
//         }
//         while(left<=mid){
//             temp.push_back(nums[left]);
//             left++;
//         }
//         while(right<=high){
//             temp.push_back(nums[right]);
//             right++;
//         }

//         for(int i=low;i<=high;i++){
//             nums[i]=temp[i-low];
//         }
//         }

//     void mergeSort(vector<int>& nums,int low,int high){
//         if(low>=high) return;
//         int mid=(low+high)/2;
//         mergeSort(nums,low,mid);
//         mergeSort(nums,mid+1,high);
//         merge(nums,low,mid,high);
//     }


//     vector<int> sortArray(vector<int>& nums) {
//         mergeSort(nums,0,nums.size()-1);
//         return nums;
//     }
// };

// Quick Sort
class Solution {
    public:
    
        int partition(vector<int>& nums,int low,int high){
            if(low>=high) return -1;
            int pivot=nums[low];
            int i=low;
            int j=high;
            while(i<j){
            while(i<=high-1 && nums[i]<=pivot){
                i++;
            }
            while(j>=low+1 && nums[j]>pivot){
                j--;
            }
            if(i<j){
                swap(nums[i],nums[j]);
            }
            }
            swap(nums[j],nums[low]);
            return j;
    
        }
    
        void quickSort(vector<int>& nums,int low,int high){
            if(low<high){
                int pIndex=partition(nums,low,high);
                quickSort(nums,low,pIndex-1);
                quickSort(nums,pIndex+1,high);
            }
        }
    
        vector<int> sortArray(vector<int>& nums) {
            quickSort(nums,0,nums.size()-1);
            return nums;
        }
    };

int main() {
    Solution sol;
    vector<int> nums = {5, 2, 3, 4, 1}; // example input
    vector<int> sorted = sol.sortArray(nums);

    for (int num : sorted) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
