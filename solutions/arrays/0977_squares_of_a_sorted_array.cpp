/*
------------------------------------------------
Problem: Squares of a Sorted Array
LeetCode: #977
Pattern: Arrays + Two Pointers
Difficulty: Easy

Description:
Given an integer array nums sorted in non-decreasing order,
return an array of the squares of each number, also sorted
in non-decreasing order.

Example:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]

Time Complexity: O(n)
Space Complexity: O(n)

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();
        vector<int> result(n);

        int left = 0;
        int right = n - 1;

        for (int i = n - 1; i >= 0; i--) {

            if (abs(nums[left]) > abs(nums[right])) {
                result[i] = nums[left] * nums[left];
                left++;
            } else {
                result[i] = nums[right] * nums[right];
                right--;
            }
        }

        return result;
    }
};