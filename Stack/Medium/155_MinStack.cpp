/* 
 * Problem: 155 
 * Name: Min Stack
 * Difficulty: Medium
 * Topic: Stack
 * Link: https://leetcode.com/problems/min-stack/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Stack-Pair Approach
// Stack will store pairs of {elements, relative-mininums}
// push: O(1)
// pop: O(1)
class MinStack {
private:
    stack<pair<int,int>> stack;

public:
    MinStack() {}
    
    void push(int val) {
        if (stack.empty()){
            stack.push({val,val});
        }
        else {
            stack.push({val, min(stack.top().second, val)});
        }
    }
    
    void pop() {
        stack.pop();
    }
    
    int top() {
        return stack.top().first;
    }
    
    int getMin() {
        return stack.top().second;
    }
};

//      Two-Stack Approach
// main stack will store all elements like a regular stack
// mins stack will only store "relative" minimum values
// push: O(1)
// pop: O(1)
class MinStack {
private:
    stack<int> main;
    stack<int> mins;

public:
    MinStack() {}
    
    void push(int val) {
        main.push(val);
        if (mins.empty()){
            mins.push(val);
        }
        else if (val <= mins.top()){
            mins.push(val);
        }
    }
    
    void pop() {
        if (main.top() == mins.top()){
            mins.pop();
        }
        main.pop();
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return mins.top();
    }
};