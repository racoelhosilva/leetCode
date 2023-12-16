/* 
 * Problem: 242 
 * Name: Valid Anagram
 * Difficulty: Easy
 * Topic: Arrays & Hashing
 * Link: https://leetcode.com/problems/valid-anagram/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Unordered_Map (any amount of chars)
// Time Complexity: O(n)
// Space Complexity: O(n)
bool isAnagramMap(string s, string t) {
    if (s.size() != t.size()){ return false;}
    unordered_map<char, int> frequencies;
    for (int idx = 0; idx < s.size(); idx++){
        frequencies[s[idx]]++;
        frequencies[t[idx]]--;
    }
    for (pair<char, int> f : frequencies){
        if (f.second != 0){return false;}
    }
    return true;
}

//      Array/Vector 26 (fixed for lowercase chars)
// Time Complexity: O(n)
// Space Complexity: O(n)
bool isAnagram(string s, string t){
    if (s.size() != t.size()){ return false;}
    vector<int> frequencies(26, 0);

    for (int idx = 0; idx < s.size(); idx++){
        ++frequencies[s[idx] - 'a'];
        --frequencies[t[idx] - 'a'];
    }
    for (int diff : frequencies){
        if (diff != 0){
            return false;
        }
    }
    return true;
}