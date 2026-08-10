/*
------------------------------------------------
Problem: Remove Duplicates from Sorted Array
LeetCode: #26
Pattern: Arrays + Two Pointers
Difficulty: Easy

Description:
Given an integer array nums sorted in non-decreasing order,
remove the duplicates in-place so that each unique element
appears only once.

Return the number of unique elements.

The first k elements of nums should contain the unique values.

Example:
Input: nums = [1,1,2]
Output: 2

The first two elements become:
[1,2]

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.empty()) {
            return 0;
        }

        int left = 1;

        for (int right = 1; right < nums.size(); right++) {

            if (nums[right] != nums[right - 1]) {
                nums[left] = nums[right];
                left++;
            }
        }

        return left;
    }
};