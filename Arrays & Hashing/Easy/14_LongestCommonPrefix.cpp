/* 
 * Problem: 14 
 * Name: Longest Common Prefix
 * Difficulty: Easy
 * Topic: Arrays & Hashing
 * Link: https://leetcode.com/problems/longest-common-prefix/
 */
 
#include <bits/stdc++.h>
using namespace std;

// Auxiliar function (LCP of two words)
// This is used in many of the methods
string longestCommonPrefixTwoStrings(string s1, string s2){
    string result = "";
    for (int idx = 0; idx < min(s1.size(), s2.size()); idx++){
        if (s1[idx] == s2[idx]){
            result.push_back(s1[idx]);
        }
        else {
            return result;
        }
    }
    return result;
}

//      Horizontal scanning
// Time Complexity: O(n²) => checks all characters
// Space Complexity: O(1)
string longestCommonPrefixHS(vector<string>& strs) {
    if (strs.empty()){ return "";}
    string result = strs[0];
    for (int idx = 1; idx < strs.size(); idx++){
        result = longestCommonPrefixTwoStrings(result, strs[idx]);
    }
    return result;
}

//      Vertical Scanning
// Time Complexity: O(n²) => runs until the prefix fails
// Space Complexity: O(1)
string longestCommonPrefixVS(vector<string>& strs){
    if (strs.empty()){ return "";}
    string result = "";
    for (int idx = 0; idx < strs[0].size(); idx++){
        char target = strs[0][idx];
        for (const string& word : strs){
            if (word.size() <= idx || word[idx] != target){
                return result;
            }
        }
        result.push_back(target);
    }
    return result;
}


//      Divide and Conquer
// Time Complexity: O(n log n)
// Space Complexity: O(1)
string longestCommonPrefixDCHelper(vector<string>& strs, int left, int right);
string longestCommonPrefixDC(vector<string>& strs){
    if (strs.empty()){ return "";}
    return longestCommonPrefixDCHelper(strs, 0, strs.size() - 1);
}
// Recursive function (Divide and Conquer)
string longestCommonPrefixDCHelper(vector<string>& strs, int left, int right){
    if (left >= right){ return strs[left];}
    int midpoint = left + (right - left) / 2;
    string lcpLow = longestCommonPrefixDCHelper(strs, left, midpoint);
    string lcpHigh = longestCommonPrefixDCHelper(strs, midpoint + 1, right);
    return longestCommonPrefixTwoStrings(lcpLow, lcpHigh);
}

//      Binary Search
// Time Complexity: O(n log n)
// Space Complexity: O(1)
bool longestCommonPrefixLengthL(vector<string>& strs, int l);
string longestCommonPrefixBS(vector<string>& strs){
    if (strs.empty()){ return "";}
    int minLength = strs[0].size();
    for (const string& s : strs){
        minLength = min(minLength, (int)s.length());
    }

    int lowerBound = 0;
    int upperBound = minLength;
    while (lowerBound <= upperBound){
        int middle = lowerBound + (upperBound - lowerBound) / 2;  
        if (longestCommonPrefixLengthL(strs, middle)){
            lowerBound = middle + 1;
        }
        else {
            upperBound = middle - 1;
        }

    }
    return strs[0].substr(0, lowerBound + (upperBound - lowerBound) / 2);
}
// Auxiliar Binary Search
bool longestCommonPrefixLengthL(vector<string>& strs, int l){
    string prefix = strs[0].substr(0, l);
    for (int idx = 1; idx < strs.size(); idx++){
        if (strs[idx].substr(0, l) != prefix){
            return false;
        }
    }
    return true;
}

//      Sorting
// Time Complexity: O(n log n)
// Space Complexity: O(1)
string longestCommonPrefixSort(vector<string>& strs){
    if (strs.empty()){ return "";}
    string result = "";
    sort(strs.begin(), strs.end());
    for (int idx = 0; idx < min(strs[0].size(), strs[strs.size()-1].size()); idx++){
        if (strs[0][idx] == strs[strs.size()-1][idx]){
            result.push_back(strs[0][idx]);
        }
        else {
            return result;
        }
    }
    return result;
}