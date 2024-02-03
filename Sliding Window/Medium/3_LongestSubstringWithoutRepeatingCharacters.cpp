/* 
 * Problem: 3 
 * Name: Longest Substring Without Repeating Characters
 * Difficulty: Medium
 * Topic: Sliding Window
 * Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Unordered Set
// Time Complexity: O(n)
// Space Complexity: O(n)
int lengthOfLongestSubstringUS(string s) {
    int result = 0;
    int left = 0, right = 0;
    unordered_set<char> chars;
    while (right < s.size()){
        while (chars.count(s[right]) > 0) {
            chars.erase(s[left]);
            left++;
        }
        chars.insert(s[right]);
        result = max(result, right - left + 1);
        right++;
    }
    return result;
}

//      Bool Vector
// Time Complexity: O(n)
// Space Complexity: O(256)
int lengthOfLongestSubstringV(string s) {
    int result = 0;
    int left = 0, right = 0;
    vector<bool> chars(256,0);
    while (right < s.size()){
        while (chars[s[right]]) {
            chars[s[left]] = 0;
            left++;
        }
        chars[s[right]] = 1;
        result = max(result, right - left + 1);
        right++;
    }
    return result;
}