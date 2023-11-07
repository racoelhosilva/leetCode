#include<bits/stdc++.h>
using namespace std;

// Instead of checking both strings, since ransomNote "depends" on the letters from the magazine
// we can just check it after checking the frequencies of the magazine 
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
