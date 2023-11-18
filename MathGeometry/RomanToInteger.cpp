#include<bits/stdc++.h>
using namespace std;

// Using unordered_map
int romanToInt(string s) {
    unordered_map<char, int> romanToDecimal = {{'I',1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}}; 
    int result = 0;
    for (int idx = 0; idx < s.size(); idx++){
        if (romanToDecimal[s[idx]] < romanToDecimal[s[idx+1]]){
            result -= romanToDecimal[s[idx]];
        }
        else {
            result += romanToDecimal[s[idx]];
        }
    }
    return result;
}


// Auxiliar Function
int romanToDecimal(const char &c){
    switch (c){
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    default:
        return 1000;
    }
}

// Using Auxiliar Function
int romanToInt(string s) {
    int result = 0;
    for (int idx = 0; idx < s.size()-1; idx++){
        if (romanToDecimal(s[idx]) < romanToDecimal(s[idx+1])){
            result -= romanToDecimal(s[idx]);
        }
        else {
            result += romanToDecimal(s[idx]);
        }
    }
    result += romanToDecimal(s[s.size()-1]);
    return result;
}
