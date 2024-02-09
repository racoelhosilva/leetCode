/* 
 * Problem: 150 
 * Name: Evaluate Reverse Polish Notation
 * Difficulty: Medium
 * Topic: Stack
 * Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Stack Structure
// Time Complexity: O(n)
// Space Complexity: O(n)
int evalRPN(vector<string>& tokens) {
    stack<int> values;
    
    for (const string& s : tokens) {
        if (s == "+"){
            int a = values.top(); values.pop();
            int b = values.top(); values.pop();
            values.push(b + a);
        }
        else if (s == "-"){
            int a = values.top(); values.pop();
            int b = values.top(); values.pop();
            values.push(b - a);
        }
        else if (s == "*"){
            int a = values.top(); values.pop();
            int b = values.top(); values.pop();
            values.push(b * a);            
        }
        else if (s == "/"){
            int a = values.top(); values.pop();
            int b = values.top(); values.pop();
            values.push(b / a);            
        }
        else {
            values.push(stoi(s));
        }
    }
    return values.top();
}