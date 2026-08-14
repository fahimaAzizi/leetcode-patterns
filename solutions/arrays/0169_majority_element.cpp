/*
------------------------------------------------
Problem: Majority Element
LeetCode: #169
Pattern: Arrays + Boyer-Moore Voting
Difficulty: Easy

Description:
Given an array nums of size n, return the majority element.

The majority element is the element that appears more
than n / 2 times.

Example:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int candidate = 0;
        int count = 0;

        for (int num : nums) {

            if (count == 0) {
                candidate = num;
            }

            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};