#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> remaining;
    for (char c : s){
        if (c == '('){ remaining.push(')');}
        else if (c == '{'){ remaining.push('}');}
        else if (c == '['){ remaining.push(']');}
        else {
            if (!remaining.empty() && remaining.top() == c){
                remaining.pop();
            }
            else {
                return false;
            }
        }
        
    }
    return remaining.empty();
}
