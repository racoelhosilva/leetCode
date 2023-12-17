/* 
 * Problem: 409 
 * Name: Longest Palindrome
 * Difficulty: Easy
 * Topic: Arrays & Hashing
 * Link: https://leetcode.com/problems/longest-palindrome/
 */
 
#include <bits/stdc++.h>
using namespace std;


//      Array (printable chars go from [32..128])
// Time Complexity: O(n)
// Space Complexity: O(1)
int longestPalindromeArray(string s){
    int frequencies[128];
    for (int idx = 0; idx < s.size(); idx++){
        frequencies[s[idx]]++;
    }
    int total = 0;
    for (int idx = 0; idx < 128; idx++){
        total += 2 * (frequencies[idx] / 2); // only even numbers
        if (total % 2 == 0 && frequencies[idx] % 2 != 0){ // allow maximum 1 odd number
            total++;
        }
    }
    return total;
}

//      Set
// Time Complexity: O(n)
// Space Complexity: O(1)
int longestPalindromeSet(string s){
    unordered_set<char> tracker;
    for (char c : s){
        if (tracker.count(c) > 0){ tracker.erase(c);}
        else {tracker.insert(c);}
    }
    if (tracker.size() <= 1) {return s.length();}
    return s.length() - tracker.size() + 1; // total size - size of odd numbers + 1
}

//      Map
// Time Complexity: O(n)
// Space Complexity: O(1)
int longestPalindromeMap(string s) {
    unordered_map<char, int> counter;
    for (char c : s){
        counter[c]++;
    }
    int total = 0;
    for (pair<char, int> p : counter){
        total += 2 * (p.second / 2); // only even numbers
        if (total % 2 == 0 && p.second % 2 != 0){ // allow maximum 1 odd number
            total++;
        }
    }
    return total;
}