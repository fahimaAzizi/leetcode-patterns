/*
------------------------------------------------
Problem: Best Time to Buy and Sell Stock
LeetCode: #121
Pattern: Arrays + Greedy
Difficulty: Easy

Description:
You are given an array prices where prices[i] is the
price of a given stock on the ith day.

Choose one day to buy one stock and choose a different
day in the future to sell that stock.

Return the maximum profit you can achieve.
If no profit can be made, return 0.

Example:
Input: prices = [7,1,5,3,6,4]
Output: 5

Explanation:
Buy on day 2 (price = 1)
Sell on day 5 (price = 6)
Profit = 6 - 1 = 5

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {

            minPrice = min(minPrice, prices[i]);

            int profit = prices[i] - minPrice;

            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};