/* 
 * Problem: 70 
 * Name: Climbing Stairs
 * Difficulty: Easy
 * Topic: Dynamic Programming (1D)
 * Link: https://leetcode.com/problems/climbing-stairs/
 */
 
#include <bits/stdc++.h>
using namespace std;


//      Simple Recursion -> Time Limit Exceeded
// Time Complexity: O(n²)
// Space Complexity: O(1)
int climbStairsRecursive(int n) {
    if (n <= 0){return 0;}
    return climbStairsRecursive(n-1) + climbStairsRecursive(n-2);      
}

//      Recursion with Memoization
// Time Complexity: O(n)
// Space Complexity: O(n)
int climbStairsMemoizationHelper(unordered_map<int, int>& memo, int n);
int climbStairsMemoization(int n) {
    unordered_map<int, int> memo;
    return climbStairsMemoizationHelper(memo, n);
}
int climbStairsMemoizationHelper(unordered_map<int, int>& memo, int n){
    if (n <= 1){return 1;}
    if (memo.count(n) == 0){
        memo[n] = climbStairsMemoizationHelper(memo, n-1) + climbStairsMemoizationHelper(memo, n-2);
    }
    return memo[n];
}

//      Tabulation (Iterative)
// Time Complexity: O(n)
// Space Complexity: O(n)
int climbStairsTabulation(int n){
    if (n <= 1){return 1;}
    vector<int> counter(n+1, 1);
    for (int idx = 2; idx <= n; idx++){
        counter[idx] = counter[idx-1] + counter[idx-2];
    }
    return counter[n];
}

//      Fibonacci-like Optimization
// Time Complexity: O(n)
// Space Complexity: O(1)
int climbStairs(int n){
    if (n <= 2){return n;}
    int twoStepBefore = 1;
    int oneStepBefore = 2;
    int total = 0;

    for (int _ = 3; _ <= n; _++){
        total = oneStepBefore + twoStepBefore;
        // Prepare next iteration
        twoStepBefore = oneStepBefore;
        oneStepBefore = total;
    }
    return total;
}
