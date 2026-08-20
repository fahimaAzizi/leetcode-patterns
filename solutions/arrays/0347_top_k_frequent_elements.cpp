/*
------------------------------------------------
Problem: Top K Frequent Elements
LeetCode: #347
Pattern: Hash Map + Bucket Sort
Difficulty: Medium

Description:
Given an integer array nums and an integer k, return the
k most frequent elements.

Example:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

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
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> frequency;

        // Count frequency of each number.
        for (int num : nums) {
            frequency[num]++;
        }

        // bucket[i] contains numbers that appear i times.
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto& pair : frequency) {
            bucket[pair.second].push_back(pair.first);
        }

        vector<int> result;

        // Start from the highest frequency.
        for (int i = bucket.size() - 1; i >= 0; i--) {

            for (int num : bucket[i]) {

                result.push_back(num);

                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};