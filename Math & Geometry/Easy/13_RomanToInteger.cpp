/* 
 * Problem: 13 
 * Name: Roman To Integer
 * Difficulty: Easy
 * Topic: Math & Geometry
 * Link: https://leetcode.com/problems/roman-to-integer/
 */
 
#include <bits/stdc++.h>
using namespace std;


//      Unordered_map
// Time Complexity: O(n)
// Space Complexity: O(1)
int romanToIntMap(string s) {
    unordered_map<char, int> romanToDecimal = {
        {'I',1}, 
        {'V', 5}, 
        {'X', 10}, 
        {'L', 50}, 
        {'C', 100}, 
        {'D', 500}, 
        {'M', 1000}}; 
    int result = 0;
    for (int idx = 0; idx < s.size(); idx++){
        if (romanToDecimal[s[idx]] < romanToDecimal[s[idx+1]]){
            result -= romanToDecimal[s[idx]];
        }
        else {
            result += romanToDecimal[s[idx]];
        }
    }
    return result;
}

//      Auxiliar Function
// Time Complexity: O(n)
// Space Complexity: O(1)
int romanToDecimal(const char &c);
int romanToInt(string s) {
    int result = 0;
    for (int idx = 0; idx < s.size()-1; idx++){
        if (romanToDecimal(s[idx]) < romanToDecimal(s[idx+1])){
            result -= romanToDecimal(s[idx]);
        }
        else {
            result += romanToDecimal(s[idx]);
        }
    }
    result += romanToDecimal(s[s.size()-1]);
    return result;
}
int romanToDecimal(const char &c){
    switch (c){
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    default:
        return 1000;
    }
}