/*
------------------------------------------------
Problem: Move Zeroes
LeetCode: #283
Pattern: Two Pointers
Difficulty: Easy

Description:
Given an integer array nums, move all 0's to the end
while maintaining the relative order of the non-zero
elements.

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

        int insertPosition = 0;

        // Move all non-zero elements to the front.
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] != 0) {
                swap(nums[insertPosition], nums[i]);
                insertPosition++;
            }
        }
    }
};