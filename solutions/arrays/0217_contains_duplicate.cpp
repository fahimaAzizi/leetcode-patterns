/*
------------------------------------------------
Problem: Contains Duplicate
LeetCode: #217
Pattern: Arrays + Hash Set
Difficulty: Easy

Description:
Given an integer array nums, return true if any value
appears at least twice in the array, and return false
if every element is distinct.

Example:
Input: nums = [1,2,3,1]
Output: true

Time Complexity: O(n)
Space Complexity: O(n)

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }

            seen.insert(num);
        }

        return false;
    }
};