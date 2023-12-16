/* 
 * Problem: 125 
 * Name: Valid Palindrome
 * Difficulty: Easy
 * Topic: Two Pointers
 * Link: https://leetcode.com/problems/valid-palindrome/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Two-Pointer Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while(left < right){
        if (!isalnum(s[left])){
            left++;
        }
        else if (!isalnum(s[right])){
            right--;
        }
        else if (tolower(s[left]) != tolower(s[right])){
            return false;
        }
        else {
            left++;
            right--;
        }
    }
    return true;
}