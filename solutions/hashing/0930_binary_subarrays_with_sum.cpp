/*
------------------------------------------------
Problem: Binary Subarrays With Sum
LeetCode: #930
Pattern: Prefix Sum + Hash Map
Difficulty: Medium

Description:
Given a binary array nums and an integer goal, return the
number of non-empty subarrays with a sum equal to goal.

Example:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4

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
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        unordered_map<int, int> prefixCount;

        prefixCount[0] = 1;

        int prefixSum = 0;
        int result = 0;

        for (int num : nums) {

            prefixSum += num;

            int needed = prefixSum - goal;

            if (prefixCount.count(needed)) {
                result += prefixCount[needed];
            }

            prefixCount[prefixSum]++;
        }

        return result;
    }
};