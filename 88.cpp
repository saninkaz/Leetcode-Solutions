#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// Solution 1

// class Solution
// {
// public:
//     void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
//     {
//         for (int i = m; i < m + n; i++)
//         {
//             if (n > 0)
//             {
//                 nums1[i] = nums2[i - m];
//             }
//         }

//         sort(nums1.begin(), nums1.end());
//     }
// };

// Solution 2

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int len = m + n;
        int gap = (len / 2) + (len % 2);
        while (gap > 0)
        {
            int left = 0;
            int right = left + gap;
            while (right < len)
            {
                if (left < m && right >= m)
                {
                    if (nums1[left] > nums2[right - m])
                    {
                        swap(nums1[left], nums2[right - m]);
                    }
                }
                else if (left >= m)
                {
                    if (nums2[left - m] > nums2[right - m])
                    {
                        swap(nums2[left - m], nums2[right - m]);
                    }
                }

                else
                {
                    if (nums1[left] > nums1[right])
                    {
                        swap(nums1[left], nums1[right]);
                    }
                }
                left++;
                right++;
            }
            if (gap == 1)
            {
                break;
            }
            gap = (gap / 2) + (gap % 2);
        }

        for (int i = m; i < m + n; i++)
        {
            nums1[i] = nums2[i - m];
        }
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;

    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    sol.merge(nums1, m, nums2, n);

    cout << "Merged nums1: ";
    for (int num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
