#include<bits/stdc++.h>
using namespace std;

// Simple Implementation
// main stack works as the ordered queue
// helper stack receives all the elements when a push occurs and then pops them out again
class MyQueueNormal {
private:
    stack<int> main;
    stack<int> helper;

public:

    void push(int x) {
        while (!main.empty()){
            helper.push(main.top());
            main.pop();
        }
        main.push(x);
        while(!helper.empty()){
            main.push(helper.top());
            helper.pop();
        }
    }
    
    int pop() {
        int x = main.top();
        main.pop();
        return x;
    }
    
    int peek() {
        return main.top();
    }
    
    bool empty() {
        return main.empty();
    }
};

// Only one Stack (with help of the Call Stack)
// Instead of passing all the elements to another stack, pop them out, try pushing the new element and then insert the previous element again
// The idea is similar to the last one, but it's recursive using the call stack
class MyQueueCallStack {
private:
    stack<int> main;

public:

    void push(int x) {
        if (main.empty()){
            main.push(x);
        }
        else {
            int current = main.top();
            main.pop();
            this->push(x);
            main.push(current);
        }
    }
    
    int pop() {
        int x = main.top();
        main.pop();
        return x;
    }
    
    int peek() {
        return main.top();
    }
    
    bool empty() {
        return main.empty();
    }
};

// Optimized Operations
// input stack keeps receiving new elements as they arrive
// when pop/peek is called, if there are no elements in the output stack, transfer everything from the input to output

class MyQueueAmortized {
private:
    stack<int> input;
    stack<int> output;
    int front;

public:

    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if (output.empty()){
            this->move();
        }
        int x = output.top();
        output.pop();
        return x;
    }
    
    int peek() {
        if (output.empty()){
            this->move();
        }
        return output.top();
    }
    
    void move(){
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};