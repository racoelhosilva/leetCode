/* 
 * Problem: 9 
 * Name: Palindrome Number
 * Difficulty: Easy
 * Topic: Math & Geometry
 * Link: https://leetcode.com/problems/palindrome-number/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Reversing the entire number
// Time Complexity: O(n)
// Space Complexity: O(1)
bool isPalindromeTotal(int x) {
    if (x < 0 || (x != 0 && x % 10 == 0)) { return false;}
    long int reversed = 0;
    int temp = x;
    while (temp > 0){
        reversed *= 10;
        reversed += temp % 10;
        temp /= 10;
    }
    return reversed == x;
}

//      Reversing half the number
// Time Complexity: O(n)
// Space Complexity: O(1)
bool isPalindromeHalf(int x) {
    if (x < 0 || (x != 0 && x % 10 == 0)) { return false;}
    long int reversed = 0;
    while (x > reversed){
        reversed *= 10;
        reversed += x % 10;
        x /= 10;
    }
    return x == reversed || x == reversed / 10;
}