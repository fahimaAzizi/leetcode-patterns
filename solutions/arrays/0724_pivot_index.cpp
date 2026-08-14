/*
------------------------------------------------
Problem: Pivot Index
LeetCode: #724
Pattern: Arrays + Prefix Sum
Difficulty: Easy

Description:
Given an array of integers nums, calculate the pivot index.

The pivot index is the index where the sum of all the numbers
strictly to the left of the index is equal to the sum of all
the numbers strictly to the right.

If no such index exists, return -1.

Example:
Input: nums = [1,7,3,6,5,6]
Output: 3

Explanation:
Left sum  = 1 + 7 + 3 = 11
Right sum = 5 + 6 = 11

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/
  
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {

            int rightSum = totalSum - leftSum - nums[i];

            if (leftSum == rightSum) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};