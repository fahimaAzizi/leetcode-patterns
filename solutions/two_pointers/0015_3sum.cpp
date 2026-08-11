/*
------------------------------------------------
Problem: 3Sum
LeetCode: #15
Pattern: Sorting + Two Pointers
Difficulty: Medium

Description:
Given an integer array nums, return all unique triplets
[a, b, c] such that:

a + b + c = 0

The solution must not contain duplicate triplets.

Example:
Input: nums = [-1,0,1,2,-1,-4]

Output:
[[-1,-1,2],[-1,0,1]]

Time Complexity: O(n²)
Space Complexity: O(1) excluding output

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;

        // Sort the array first.
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {

            // Skip duplicate values.
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {

                    result.push_back({
                        nums[i],
                        nums[left],
                        nums[right]
                    });

                    left++;
                    right--;

                    // Skip duplicates.
                    while (left < right &&
                           nums[left] == nums[left - 1]) {
                        left++;
                    }

                    while (left < right &&
                           nums[right] == nums[right + 1]) {
                        right--;
                    }
                }

                else if (sum < 0) {
                    left++;
                }

                else {
                    right--;
                }
            }
        }

        return result;
    }
};