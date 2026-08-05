/*
------------------------------------------------
Problem: Running Sum of 1D Array
LeetCode: #1480
Pattern: Arrays + Prefix Sum
Difficulty: Easy

Description:
Given an array nums.
Return the running sum of nums.

The running sum of an array is defined as:
runningSum[i] = sum(nums[0]...nums[i])

Example:
Input: nums = [1,2,3,4]
Output: [1,3,6,10]

Explanation:
1
1+2 = 3
1+2+3 = 6
1+2+3+4 = 10

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }

        return nums;
    }
};