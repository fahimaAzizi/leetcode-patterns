/*
------------------------------------------------
Problem: Merge Sorted Array
LeetCode: #88
Pattern: Arrays + Two Pointers
Difficulty: Easy

Description:
You are given two integer arrays nums1 and nums2,
sorted in non-decreasing order, and two integers
m and n, representing the number of elements in
nums1 and nums2 respectively.

Merge nums2 into nums1 as one sorted array.

The final sorted array should not be returned by
the function, but instead be stored inside nums1.

Example:
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6], n = 3

Output:
[1,2,2,3,5,6]

Time Complexity: O(m + n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {

            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }

        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};