/*
------------------------------------------------
Problem: Missing Number
LeetCode: #268
Pattern: Arrays + XOR
Difficulty: Easy

Description:
Given an array nums containing n distinct numbers in the
range [0, n], return the only number in the range that is
missing from the array.

Example:
Input: nums = [3,0,1]
Output: 2

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int result = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            result ^= i;
            result ^= nums[i];
        }

        return result;
    }
};