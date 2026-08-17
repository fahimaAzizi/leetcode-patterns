/*
------------------------------------------------
Problem: Intersection of Two Arrays
LeetCode: #349
Pattern: Arrays + Hash Set
Difficulty: Easy

Description:
Given two integer arrays nums1 and nums2, return an array
of their intersection.

Each element in the result must be unique.

Example:
Input:
nums1 = [1,2,2,1]
nums2 = [2,2]

Output:
[2]

Time Complexity: O(n + m)
Space Complexity: O(n + m)

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> resultSet;

        for (int num : nums2) {
            if (set1.count(num)) {
                resultSet.insert(num);
            }
        }

        return vector<int>(resultSet.begin(), resultSet.end());
    }
};