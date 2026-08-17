/*
------------------------------------------------
Problem: Check If N and Its Double Exist
LeetCode: #1346
Pattern: Arrays + Hash Set
Difficulty: Easy

Description:
Given an array arr of integers, check if there exist
two indices i and j such that:

i != j

and

arr[i] == 2 * arr[j]

Example:
Input: arr = [10,2,5,3]
Output: true

Explanation:
5 == 2 * 2

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
    bool checkIfExist(vector<int>& arr) {

        unordered_set<int> seen;

        for (int num : arr) {

            if (seen.count(num * 2)) {
                return true;
            }

            if (num % 2 == 0 && seen.count(num / 2)) {
                return true;
            }

            seen.insert(num);
        }

        return false;
    }
};