/*
------------------------------------------------
Problem: Two Sum II - Input Array Is Sorted
LeetCode: #167
Pattern: Two Pointers
Difficulty: Medium

Description:
Given a 1-indexed array of integers that is already sorted,
find two numbers such that they add up to a specific target.

Return their indices (1-indexed).

Example:
Input:
numbers = [2,7,11,15]
target = 9

Output:
[1,2]

Explanation:
2 + 7 = 9

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {

            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1};
            }

            else if (sum < target) {
                left++;
            }

            else {
                right--;
            }
        }

        return {};
    }
};