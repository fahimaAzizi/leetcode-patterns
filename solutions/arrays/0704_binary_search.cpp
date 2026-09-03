/*
------------------------------------------------
Problem: Binary Search
LeetCode: #704
Pattern: Binary Search
Difficulty: Easy

Description:
Given a sorted array of integers nums and an integer target,
return the index of target if it exists.

If target does not exist, return -1.

Example:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4

Time Complexity: O(log n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {

            int middle = left + (right - left) / 2;

            if (nums[middle] == target) {
                return middle;
            }

            if (nums[middle] < target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return -1;
    }
};