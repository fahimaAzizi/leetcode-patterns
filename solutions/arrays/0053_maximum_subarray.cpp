/*
------------------------------------------------
Problem: Maximum Subarray
LeetCode: #53
Pattern: Arrays + Kadane's Algorithm
Difficulty: Medium

Description:
Given an integer array nums, find the subarray with the
largest sum and return its sum.

A subarray is a contiguous part of an array.

Example:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6

Explanation:
The subarray [4,-1,2,1] has the largest sum:
4 + (-1) + 2 + 1 = 6

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currentSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            currentSum = max(nums[i], currentSum + nums[i]);

            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};