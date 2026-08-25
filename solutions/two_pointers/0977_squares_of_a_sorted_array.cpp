/*
------------------------------------------------
Problem: Squares of a Sorted Array
LeetCode: #977
Pattern: Two Pointers
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

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();

        vector<int> result(n);

        int left = 0;
        int right = n - 1;

        // Fill the result from right to left.
        for (int i = n - 1; i >= 0; i--) {

            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare) {
                result[i] = leftSquare;
                left++;
            } else {
                result[i] = rightSquare;
                right--;
            }
        }

        return result;
    }
};
