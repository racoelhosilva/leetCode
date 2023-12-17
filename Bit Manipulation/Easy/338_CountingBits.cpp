/* 
 * Problem: 338 
 * Name: Counting Bits
 * Difficulty: Easy
 * Topic: Bit Manipulation
 * Link: https://leetcode.com/problems/counting-bits/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Brute Force
// Time Complexity: O(n²)
// Space Complexity: O(n)
vector<int> countBitsBruteForce(int n) {
    vector<int> result(n+1);
    for (int idx = 0; idx <= n; idx++){
        int counter = 0;
        int number = idx;
        while (number != 0){
            counter += number % 2;
            number = number / 2;
        }
        result[idx] = counter;
    }
    return result;
}

//      Recurrence Approach
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> countBits(int n) {
    vector<int> result(n+1,0);
    for (int idx = 1; idx <= n; idx++){
        result[idx] = result[idx/2] + idx % 2;
    }
    return result;
}