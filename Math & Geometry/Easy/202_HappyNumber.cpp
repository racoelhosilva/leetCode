/* 
 * Problem: 202 
 * Name: Happy Number
 * Difficulty: Easy
 * Topic: Math & Geometry
 * Link: https://leetcode.com/problems/happy-number/
 */
 
#include <bits/stdc++.h>
using namespace std;

// Auxiliar Function (Calculate the new number)
int newNumber(int n){
    int result = 0;
    while (n != 0){
        result += (n % 10) * (n % 10);
        n /= 10;
    }
    return result;
}

//      Hash Set
// Time Complexity: O(n)
// Space Complexity: O(n)
bool isHappyHashSet(int n) {
    unordered_set<int> previous;
    while (n != 1){
        previous.insert(n);
        n = newNumber(n);
        if (previous.count(n) != 0){
            return false;
        }
    }   
    return true;     
}

//      Floyd's Cycle Detection
// Time Complexity: O(n)
// Space Complexity: O(1)
bool isHappyFloydCycle(int n) {
    int slow = n;
    int fast = newNumber(n);
    while(fast != 1){
        slow = newNumber(slow);
        fast = newNumber(newNumber(fast));
        if (slow == fast){
            return false;
        }
    } 
    return true;
}