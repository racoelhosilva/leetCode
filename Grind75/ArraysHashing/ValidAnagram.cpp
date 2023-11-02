#include<bits/stdc++.h>
using namespace std;

// Using Unordered_Map (works for any type of characters)
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

// Using Vector of 26 (we know only lowercase alphabetic characters)
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