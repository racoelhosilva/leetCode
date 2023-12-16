/* 
 * Problem: 704 
 * Name: Binary Search
 * Difficulty: Easy
 * Topic: Binary Search
 * Link: https://leetcode.com/problems/binary-search/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Binary Seach
// Time Complexity: O(log n)
// Space Complexity: O(1)
int search(vector<int>& nums, int target) {
    int lowerBound = 0;
    int upperBound = nums.size() - 1;

    while (lowerBound <= upperBound){
        // Note: using this operation we avoid overflow errors
        int midValue = lowerBound + (upperBound - lowerBound) / 2;

        if (nums[midValue] < target){
            lowerBound = midValue + 1;
        }
        else if (target < nums[midValue]){
            upperBound = midValue - 1;
        }
        else {
            return midValue;
        }
    }
    return -1;
}