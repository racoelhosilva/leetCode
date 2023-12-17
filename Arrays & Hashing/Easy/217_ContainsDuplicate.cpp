/* 
 * Problem: 217 
 * Name: Contains Duplicate
 * Difficulty: Easy
 * Topic: Arrays & Hashing
 * Link: https://leetcode.com/problems/contains-duplicate/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Set
// Time Complexity: O(n)
// Space Complexity: O(1)
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> passed;
    for (int n : nums){
        if (passed.count(n) == 0){
            passed.insert(n);
        }
        else {
            return true;
        }
    }
    return false;
}