#include<bits/stdc++.h>
using namespace std;

// Using a big array
// Printable chars go from [32..128]
int longestPalindrome(string s){
    int frequencies[128];
    for (int idx = 0; idx < s.size(); idx++){
        frequencies[s[idx]]++;
    }
    int total = 0;
    for (int idx = 0; idx < 128; idx++){
        total += 2 * (frequencies[idx] / 2);
        if (total % 2 == 0 && frequencies[idx] % 2 != 0){
            total++;
        }
    }
    return total;
}

// Using a Set
int longestPalindrome(string s){
    unordered_set<char> tracker;
    for (char c : s){
        if (tracker.count(c) > 0){ tracker.erase(c);}
        else {tracker.insert(c);}
    }
    if (tracker.size() <= 1) {return s.length();}
    return s.length() - tracker.size() + 1;
}

// Using a map
int longestPalindrome(string s) {
    unordered_map<char, int> counter;
    for (char c : s){
        counter[c]++;
    }
    int total = 0;
    for (pair<char, int> p : counter){
        total += 2 * (p.second / 2);
        if (total % 2 == 0 && p.second % 2 != 0){
            total++;
        }
    }
    return total;
}