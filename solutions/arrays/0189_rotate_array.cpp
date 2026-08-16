/*
------------------------------------------------
Problem: Rotate Array
LeetCode: #189
Pattern: Arrays + Reverse
Difficulty: Medium

Description:
Given an integer array nums, rotate the array to the
right by k steps.

Example:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

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
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        k = k % n;

        reverse(nums.begin(), nums.end());

        reverse(nums.begin(), nums.begin() + k);

        reverse(nums.begin() + k, nums.end());
    }
};