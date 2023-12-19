/* 
 * Problem: 1046 
 * Name: Last Stone Weight
 * Difficulty: Easy
 * Topic: Priority Queue
 * Link: https://leetcode.com/problems/last-stone-weight/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Naive Approach
// Time Complexity: O(n log n)
// Space Complexity: O(1)
int lastStoneWeightNaive(vector<int>& stones) {
    while (stones.size() > 1){
        sort(stones.begin(), stones.end());
        int largest = stones[stones.size()-1];
        int secondLargest = stones[stones.size()-2];
        stones.pop_back();
        if (largest == secondLargest){
            stones.pop_back();
        }
        else {
            stones[stones.size()-1] = largest-secondLargest;
        }
    }
    return stones.empty() ? 0 : stones[0];
}

//      Priority Queue
// Time Complexity: O(n)
// Space Complexity: O(n)
int lastStoneWeightPQ(vector<int>& stones) {
    priority_queue<int> remainingStones(stones.begin(), stones.end());
    while (remainingStones.size() > 1){
        int largest = remainingStones.top(); remainingStones.pop();
        int secondLargest = remainingStones.top(); remainingStones.pop();
        remainingStones.push(largest - secondLargest);
    }
    return remainingStones.top();
}