/*
------------------------------------------------
Problem: Maximum Average Subarray I
LeetCode: #643
Pattern: Sliding Window
Difficulty: Easy

Description:
Given an integer array nums and an integer k, find the
contiguous subarray of length k that has the maximum
average value.

Example:
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75

Explanation:
The subarray [12,-5,-6,50] has the maximum average.

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int windowSum = 0;

        // Calculate the first window.
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        int maxSum = windowSum;

        // Slide the window.
        for (int i = k; i < nums.size(); i++) {

            windowSum += nums[i];
            windowSum -= nums[i - k];

            maxSum = max(maxSum, windowSum);
        }

        return static_cast<double>(maxSum) / k;
    }
};