/*
------------------------------------------------
Problem: Longest Consecutive Sequence
LeetCode: #128
Pattern: Hash Set
Difficulty: Medium

Description:
Given an unsorted array of integers nums, return the
length of the longest consecutive elements sequence.

Example:
Input: nums = [100,4,200,1,3,2]
Output: 4

Explanation:
The longest consecutive sequence is [1,2,3,4].

Time Complexity: O(n)
Space Complexity: O(n)

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> numbers(nums.begin(), nums.end());

        int longest = 0;

        for (int num : numbers) {

            // Start only if num is the beginning of a sequence.
            if (!numbers.count(num - 1)) {

                int current = num;
                int length = 1;

                while (numbers.count(current + 1)) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};