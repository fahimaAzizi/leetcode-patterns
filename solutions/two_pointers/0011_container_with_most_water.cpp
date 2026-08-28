/*
------------------------------------------------
Problem: Container With Most Water
LeetCode: #11
Pattern: Two Pointers
Difficulty: Medium

Description:
Given an array of heights, find two lines that together
with the x-axis form a container that holds the maximum
amount of water.

Example:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49

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
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {

            int width = right - left;

            int currentHeight = min(
                height[left],
                height[right]
            );

            int area = width * currentHeight;

            maxWater = max(maxWater, area);

            // Move the pointer with the smaller height.
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};