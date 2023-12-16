/* 
 * Problem: 121 
 * Name: Best Time To Buy And Sell Stock
 * Difficulty: Easy
 * Topic: Sliding Window
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(1)
int maxProfit(vector<int>& prices) {
    int profit = 0;
    int minVal = prices[0];
    for (const int &val : prices){
        minVal = min(minVal, val);
        profit = max(profit, val - minVal);
    }
    return profit;
}