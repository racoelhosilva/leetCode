#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int profit = 0;
    int minVal = prices[0];
    for (const int val : prices){
        minVal = min(minVal, val);
        profit = max(profit, val - minVal);
    }
    return profit;
}