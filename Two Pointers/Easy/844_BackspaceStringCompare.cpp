/* 
 * Problem: 844 
 * Name: Backspace String Compare
 * Difficulty: Easy
 * Topic: Two Pointers
 * Link: https://leetcode.com/problems/backspace-string-compare/
 */
 
#include <bits/stdc++.h>
using namespace std;


//      Stack
// Time Complexity: O(n)
// Space Complexity: O(n)
string stringBuilderStack(string s);
bool backspaceCompareStack(string s, string t) {
    return stringBuilderStack(s) == stringBuilderStack(t);
}
string stringBuilderStack(string s){
    stack<char> chars;
    for (const char &c : s){
        if (c == '#'){
            if (!chars.empty()){
                chars.pop();
            }
        }
        else {
            chars.push(c);
        }
    }
    string result;
    while (!chars.empty()){
        result.push_back(chars.top());
        chars.pop();
    }
    return result;
}

//      Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)
string stringBuilder(string s);
bool backspaceCompare(string s, string t) {
    return stringBuilder(s) == stringBuilder(t);
}
string stringBuilder(string s){
    int p2 = 0;
    for(int p1 = 0; p1 < s.size(); p1++){
        if (s[p1] == '#'){
            p2--;
            p2 = max(0, p2);
        }
        else {
            s[p2] = s[p1];
            p2++;
        }
    }
    return s.substr(0, p2);
}

