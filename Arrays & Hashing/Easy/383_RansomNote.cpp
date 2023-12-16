/* 
 * Problem: 383 
 * Name: Ransom Note
 * Difficulty: Easy
 * Topic: Arrays & Hashing
 * Link: https://leetcode.com/problems/ransom-note/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Hashing Array
// Time Complexity: O(n)
// Space Complexity: O(1) 
bool canConstruct(string ransomNote, string magazine) {
    if (ransomNote.size() > magazine.size()) {return false;}
    int frequencies[26] = {0};
    for (int idx = 0; idx < magazine.size(); idx++){
        frequencies[magazine[idx] - 'a']++;
    }
    for (int idx = 0; idx < ransomNote.size(); idx++){
        if (frequencies[ransomNote[idx] - 'a']-- <= 0){
            return false;
        }
    }
    return true;
}