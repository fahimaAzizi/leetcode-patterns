/*
------------------------------------------------
Problem: Subarray Product Less Than K
LeetCode: #713
Pattern: Sliding Window + Two Pointers
Difficulty: Medium

Description:
Given an array of positive integers nums and an integer k,
return the number of contiguous subarrays where the product
of all elements is strictly less than k.

Example:
Input: nums = [10,5,2,6], k = 100
Output: 8

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if (k <= 1) {
            return 0;
        }

        int left = 0;
        int product = 1;
        int count = 0;

        for (int right = 0; right < nums.size(); right++) {

            product *= nums[right];

            // Shrink the window if product is too large.
            while (product >= k) {
                product /= nums[left];
                left++;
            }

            // Count all valid subarrays ending at right.
            count += right - left + 1;
        }

        return count;
    }
};