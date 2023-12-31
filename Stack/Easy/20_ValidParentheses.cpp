/* 
 * Problem: 20 
 * Name: Valid Parentheses
 * Difficulty: Easy
 * Topic: Stack
 * Link: https://leetcode.com/problems/valid-parentheses/
 */
 
#include <bits/stdc++.h>
using namespace std;


//      Stack
// Time Complexity: O(n)
// Space Complexity: O(n)
bool isValid(string s) {
    stack<char> remaining;
    for (char c : s){
        if (c == '('){ remaining.push(')');}
        else if (c == '{'){ remaining.push('}');}
        else if (c == '['){ remaining.push(']');}
        else {
            if (!remaining.empty() && remaining.top() == c){
                remaining.pop();
            }
            else {
                return false;
            }
        }
        
    }
    return remaining.empty();
}