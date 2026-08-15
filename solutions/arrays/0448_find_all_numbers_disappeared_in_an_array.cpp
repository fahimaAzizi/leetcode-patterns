/*
------------------------------------------------
Problem: Find All Numbers Disappeared in an Array
LeetCode: #448
Pattern: Arrays + In-Place Hashing
Difficulty: Easy

Description:
Given an integer array nums of length n where nums[i]
is in the range [1, n], return all the integers in the
range [1, n] that do not appear in nums.

Example:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Time Complexity: O(n)
Space Complexity: O(1) extra space

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        for (int num : nums) {

            int index = abs(num) - 1;

            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }

        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};