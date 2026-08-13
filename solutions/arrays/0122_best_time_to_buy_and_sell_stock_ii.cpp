/*
------------------------------------------------
Problem: Best Time to Buy and Sell Stock II
LeetCode: #122
Pattern: Arrays + Greedy
Difficulty: Medium

Description:
You are given an array prices where prices[i] is the
price of a stock on day i.

You may buy and sell the stock multiple times, but you
can only hold one stock at a time.

Return the maximum profit you can achieve.

Example:
Input: prices = [7,1,5,3,6,4]
Output: 7

Explanation:
Buy at 1 and sell at 5 -> profit = 4
Buy at 3 and sell at 6 -> profit = 3
Total profit = 7

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {

            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};