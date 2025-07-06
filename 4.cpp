#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Brute solution (worked in leetcode)

// class Solution
// {
// public:
//     double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
//     {

//         int n1 = nums1.size();
//         int n2 = nums2.size();

//         vector<int> merged;

//         int i = 0, j = 0;

//         while (i < n1 && j < n2)
//         {
//             if (nums1[i] < nums2[j])
//             {
//                 merged.push_back(nums1[i]);
//                 i++;
//             }
//             else
//             {
//                 merged.push_back(nums2[j]);
//                 j++;
//             }
//         }

//         while (i < n1)
//         {
//             merged.push_back(nums1[i]);
//             i++;
//         }

//         while (j < n2)
//         {
//             merged.push_back(nums2[j]);
//             j++;
//         }

//         double median;

//         if ((n1 + n2) % 2 == 0)
//         {
//             median = (merged[(((n1 + n2) / 2) - 1)] + merged[(n1 + n2) / 2]) / 2.0;
//         }
//         else
//         {
//             median = merged[(n1 + n2) / 2];
//         }
//         return median;
//     }
// };

// Better solution

// class Solution
// {
// public:
//     double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
//     {

//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         int n = n1 + n2;

//         int i = 0, j = 0;
//         int index1 = (n / 2) - 1, index2 = n / 2;
//         int el1 = 0, el2 = 0;
//         int count = 0;

//         while (i < n1 && j < n2)
//         {
//             if (nums1[i] < nums2[j])
//             {
//                 if (count == index1) el1 = nums1[i];
//                 if (count == index2) el2 = nums1[i];
//                 count++;
//                 i++;
//             }
//             else
//             {
//                 if (count == index1) el1 = nums2[j];
//                 if (count == index2) el2 = nums2[j];
//                 count++;
//                 j++;
//             }
//         }

//         while (i < n1)
//         {
//             if (count == index1) el1 = nums1[i];
//             if (count == index2) el2 = nums1[i];
//             count++;
//             i++;
//         }

//         while (j < n2)
//         {
//             if (count == index1) el1 = nums2[j];
//             if (count == index2) el2 = nums2[j];
//             count++;
//             j++;
//         }

//         double median;

//         if ((n1 + n2) % 2 == 0)
//         {
//             median = (el1+el2) / 2.0;
//         }
//         else
//         {
//             median = el2;
//         }
//         return median;
//     }
// };

// Optimal solution (Binary search)

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        int n1 = nums1.size();
        int n2 = nums2.size();
        int min_n = min(n1, n2);

        int low = 0, high = min_n;
        int left = (n1 + n2 + 1) / 2;
        while (low <= high)
        {
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = nums1[mid1], r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];
            if (l1 <= r2 && l2 <= r1)
            {
                if (n1 + n2 % 2 == 0)
                {
                    return (((double)max(l1, l2)) + ((double)min(r1, r2)) / 2.0);
                }
                else
                {
                    return ((double)max(l1, l2));
                }
            }
            else if (l1 > r2)
            {
                high = mid1 - 1;
            }
            else
            {
                low = mid1 + 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {2, 4};
    vector<int> nums2 = {1, 3, 4};

    double result = sol.findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << result << endl;

    return 0;
}
