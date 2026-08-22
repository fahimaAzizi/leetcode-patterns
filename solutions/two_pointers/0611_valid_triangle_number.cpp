/*
------------------------------------------------
Problem: Valid Triangle Number
LeetCode: #611
Pattern: Sorting + Two Pointers
Difficulty: Medium

Description:
Given an integer array nums, return the number of triplets
that can form a valid triangle.

For three sides a, b, and c to form a triangle:

a + b > c

Example:
Input: nums = [2,2,3,4]
Output: 3

Time Complexity: O(n²)
Space Complexity: O(1) excluding sorting

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int count = 0;
        int n = nums.size();

        // Fix the largest side.
        for (int k = n - 1; k >= 2; k--) {

            int left = 0;
            int right = k - 1;

            while (left < right) {

                if (nums[left] + nums[right] > nums[k]) {

                    // All numbers between left and right
                    // can form valid triangles with nums[right]
                    // and nums[k].
                    count += right - left;

                    right--;

                } else {
                    left++;
                }
            }
        }

        return count;
    }
};