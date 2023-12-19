/* 
 * Problem: 746 
 * Name: Min Cost Climbing Stairs
 * Difficulty: Easy
 * Topic: Dynamic Programming 1D
 * Link: https://leetcode.com/problems/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Storing the minimum values for each of the steps
// Time Complexity: O(n)
// Space Complexity: O(n)
int minCostClimbingStairsMemo(vector<int>& cost) {
    if (cost.size() < 2) {return 0;}
    vector<int> minStepCost(cost.size()+1, 0);
    for (int step = 2; step <= cost.size(); step++){
        minStepCost[step] = min(minStepCost[step-2] + cost[step-2], minStepCost[step-1] + cost[step-1]);
    }
    return minStepCost[cost.size()];
}

//      Storing the minimum values of the previous two steps
// Time Complexity: O(n)
// Space Complexity: O(1)
int minCostClimbingStairsMemoPrevious(vector<int>& cost) {
    if (cost.size() < 2) {return 0;}
    vector<int> minStepCost(2, 0);
    for (int step = 2; step <= cost.size(); step++){
        minStepCost[step % 2] = min(minStepCost[(step-2) % 2] + cost[step-2], minStepCost[(step-1) % 2] + cost[step-1]);
    }
    return minStepCost[cost.size() % 2];
}

//      Fibonacci-like approach
// Time Complexity: O(n)
// Space Complexity: O(1)
int minCostClimbingStairsFibonacci(vector<int>& cost) {
    if (cost.size() < 2) {return 0;}
    int twoStepBefore = cost[0];
    int oneStepBefore = cost[1];
    for (int step = 2; step < cost.size(); step++){
        int current = cost[step] + min(oneStepBefore, twoStepBefore);
        twoStepBefore = oneStepBefore;
        oneStepBefore = current;
    }
    return min(oneStepBefore, twoStepBefore);
}
