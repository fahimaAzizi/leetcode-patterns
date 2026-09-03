/*
------------------------------------------------
Problem: Search Insert Position
LeetCode: #35
Pattern: Binary Search
Difficulty: Easy

Description:
Given a sorted array of distinct integers and a target value,
return the index if the target is found.

If the target is not found, return the index where it
would be inserted in order.

Example:
Input: nums = [1,3,5,6], target = 2
Output: 1

Time Complexity: O(log n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

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

        // left is the correct insertion position
        return left;
    }
};