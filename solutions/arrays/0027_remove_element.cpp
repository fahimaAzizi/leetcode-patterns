/*
------------------------------------------------
Problem: Remove Element
LeetCode: #27
Pattern: Arrays + Two Pointers
Difficulty: Easy

Description:
Given an integer array nums and an integer val, remove
all occurrences of val in-place.

Return the number of elements that are not equal to val.

Example:
Input: nums = [3,2,2,3], val = 3
Output: 2

The first two elements become:
[2,2]

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int left = 0;

        for (int right = 0; right < nums.size(); right++) {

            if (nums[right] != val) {
                nums[left] = nums[right];
                left++;
            }
        }

        return left;
    }
};