/* 
 * Problem: 66 
 * Name: Plus One
 * Difficulty: Easy
 * Topic: Math & Geometry
 * Link: https://leetcode.com/problems/plus-one/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Right->Left
// Time Complexity: O(n) => number of 9 digits from right->left
// Space Complexity: O(1)
vector<int> plusOne(vector<int>& digits) {
    int lastPosition = digits.size()-1;
    while (digits[lastPosition] == 9){
        digits[lastPosition] = 0;
        if (lastPosition == 0){
            digits.push_back(0);
            break;
        }
        else {
            lastPosition--;
        }
    }
    digits[lastPosition]++;
    return digits;  
}