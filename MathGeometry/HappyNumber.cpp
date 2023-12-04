#include<bits/stdc++.h>
using namespace std;

// Auxiliar Function
int newNumber(int n){
    int result = 0;
    while (n != 0){
        result += (n % 10) * (n % 10);
        n /= 10;
    }
    return result;
}

// Hash Set Solution
bool isHappy(int n) {
    unordered_set<int> previous;
    while (n != 1){
        previous.insert(n);
        n = newNumber(n);
        if (previous.count(n) != 0){
            return false;
        }
    }   
    return true;     
}

// Floyd's Cycle Detection
bool isHappy(int n) {
    int slow = n;
    int fast = newNumber(n);
    while(fast != 1){
        slow = newNumber(slow);
        fast = newNumber(newNumber(fast));
        if (slow == fast){
            return false;
        }
    } 
    return true;
}
