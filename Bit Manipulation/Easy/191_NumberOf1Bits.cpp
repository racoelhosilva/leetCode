/* 
 * Problem: 191 
 * Name: Number Of 1 Bits
 * Difficulty: Easy
 * Topic: Bit Manipulation
 * Link: https://leetcode.com/problems/number-of-1-bits/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Brute-Force
// Time Complexity: O(n) => number of bits
// Space Complexity: O(1)
int hammingWeightBruteForce(uint32_t n) {
    int count = 0;
    while (n != 0){
        if (n % 2 != 0){
            count++;
        }
        n = n >> 1;
    }
    return count;
}

//      Bit Manipulation Strategy
// Time Complexity: O(n) => number of 1 bits
// Space Complexity: O(1)
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0){
        n &= n-1;
        count++;
    }
    return count;
}