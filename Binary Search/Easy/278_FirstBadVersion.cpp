/* 
 * Problem: 278 
 * Name: First Bad Version
 * Difficulty: Easy
 * Topic: Binary Search
 * Link: https://leetcode.com/problems/first-bad-version/
 */
 
#include <bits/stdc++.h>
using namespace std;

// Auxiliar function (knows which versions are bad)
bool isBadVersion(int version){
    return version <= 73;
}

//      Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)
int firstBadVersion(int n) {
    int lowerBound = 0;
    int upperBound = n;
    while (!isBadVersion(lowerBound)){
        // Expression used to avoid overflow!!
        int midValue = lowerBound + (upperBound - lowerBound) / 2; 
        if (isBadVersion(midValue)){
            // If midValue is the fbv, then upperBound = midValue - 1 might skip the fbv
            upperBound = midValue; 
        }
        else {
            lowerBound = midValue + 1;
        }
    }
    return lowerBound;
}