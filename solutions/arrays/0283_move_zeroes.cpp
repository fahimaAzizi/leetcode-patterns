/*
------------------------------------------------
Problem: Move Zeroes
LeetCode: #283
Pattern: Arrays + Two Pointers
Difficulty: Easy

Description:
Given an integer array nums, move all 0's to the end
of it while maintaining the relative order of the
non-zero elements.

You must do this in-place without making a copy
of the array.

Example:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int left = 0;

        for (int right = 0; right < nums.size(); right++) {

            if (nums[right] != 0) {

                swap(nums[left], nums[right]);

                left++;
            }
        }
    }
};