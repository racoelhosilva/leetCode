#include<bits/stdc++.h>
using namespace std;

// Simple Recursion -> Time Limit Exceeded
int climbStairsRecursive(int n) {
    if (n <= 0){return 0;}
    return climbStairsRecursive(n-1) + climbStairsRecursive(n-2);      
}

// Recursion with Memoization
int climbStairsMemo(int n) {
    unordered_map<int, int> memo;
    return climbStairsMemoization(memo, n);
}
int climbStairsMemoization(unordered_map<int, int>& memo, int n){
    if (n <= 1){return 1;}
    if (memo.count(n) == 0){
        memo[n] = climbStairsMemoization(memo, n-1) + climbStairsMemoization(memo, n-2);
    }
    return memo[n];
}

// Tabulation
int climbStairsTabulation(int n){
    if (n <= 1){return 1;}
    vector<int> counter(n+1, 1);
    for (int idx = 2; idx <= n; idx++){
        counter[idx] = counter[idx-1] + counter[idx-2];
    }
    return counter[n];
}

// Fibonacci-like Otimization
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