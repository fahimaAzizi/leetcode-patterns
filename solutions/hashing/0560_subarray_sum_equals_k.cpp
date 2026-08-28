/*
------------------------------------------------
Problem: Subarray Sum Equals K
LeetCode: #560
Pattern: Prefix Sum + Hash Map
Difficulty: Medium

Description:
Given an integer array nums and an integer k, return the
total number of subarrays whose sum equals k.

Example:
Input: nums = [1,1,1], k = 2
Output: 2

Explanation:
The subarrays [1,1] at indices [0,1] and [1,2]
both have a sum of 2.

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
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> prefixCount;

        // One way to have a prefix sum of 0 before starting.
        prefixCount[0] = 1;

        int prefixSum = 0;
        int result = 0;

        for (int num : nums) {

            prefixSum += num;

            // We need a previous prefix sum equal to:
            // prefixSum - k
            int needed = prefixSum - k;

            if (prefixCount.count(needed)) {
                result += prefixCount[needed];
            }

            prefixCount[prefixSum]++;
        }

        return result;
    }
};