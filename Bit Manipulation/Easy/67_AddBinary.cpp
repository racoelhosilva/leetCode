/* 
 * Problem: 67 
 * Name: Add Binary
 * Difficulty: Easy
 * Topic: Bit Manipulation
 * Link: https://leetcode.com/problems/add-binary/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Right->Left with Carry (+ String Reverse)
// Time Complexity: O(n)
// Space Complexity: O(n)
string addBinary(string a, string b) {
    int aidx = a.size() - 1;
    int bidx = b.size() - 1;
    int carry;
    string result = "";
    
    while (aidx >= 0 || bidx >= 0){
        int sum = carry;
        if (aidx >= 0){ 
            sum += a[aidx] - '0'; 
            aidx--;
        }
        if (bidx >= 0){ 
            sum += b[bidx] - '0'; 
            bidx--;
        }
        carry = sum / 2;
        result.append(to_string(sum % 2));
    } 
    if (carry == 1) {
        result.append(to_string(carry));
    }
    reverse(result.begin(), result.end());
    return result;
}