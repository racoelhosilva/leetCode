#include<bits/stdc++.h>
using namespace std;

// Horizontal scanning
string longestCommonPrefixHS(vector<string>& strs) {
    if (strs.empty()){ return "";}
    string result = strs[0];
    for (int idx = 1; idx < strs.size(); idx++){
        result = longestCommonPrefixHSHelper(result, strs[idx]);
    }
    return result;
}

// Auxiliar function
string longestCommonPrefixHSHelper(string s1, string s2){
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

// Vertical Scanning
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


// Divide and Conquer
string longestCommonPrefix(vector<string>& strs){
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

// Auxiliar function
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

// Binary Search
string longestCommonPrefix(vector<string>& strs){
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

// Sorting
string longestCommonPrefix(vector<string>& strs){
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
