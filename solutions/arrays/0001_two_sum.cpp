/*
------------------------------------------------
Problem: Two Sum
LeetCode: #1
Pattern: Arrays + Hash Map
Difficulty: Easy

Description:
Given an array of integers nums and an integer target,
return the indices of the two numbers such that they add
up to target.

Time Complexity: O(n)
Space Complexity: O(n)

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};