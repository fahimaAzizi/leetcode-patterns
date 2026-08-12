/*
------------------------------------------------
Problem: Product of Array Except Self
LeetCode: #238
Pattern: Arrays + Prefix/Suffix Products
Difficulty: Medium

Description:
Given an integer array nums, return an array answer
such that answer[i] is equal to the product of all
the elements of nums except nums[i].

The solution must run in O(n) time and cannot use
division.

Example:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Time Complexity: O(n)
Space Complexity: O(1) extra space
------------------------------------------------
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> answer(n, 1);

        // Store products of all elements to the left
        int prefix = 1;

        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        // Multiply by products of all elements to the right
        int suffix = 1;

        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};