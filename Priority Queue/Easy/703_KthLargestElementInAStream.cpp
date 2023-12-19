/* 
 * Problem: 703 
 * Name: Kth Largest Element In A Stream
 * Difficulty: Easy
 * Topic: Priority Queue
 * Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/
 */
 
#include <bits/stdc++.h>
using namespace std;

class KthLargest {
private:
    // Priority Queue (Min Heap)
    priority_queue<int, vector<int>, greater<int>> values;
    int size;

public:
    // Constructor accepts values but restrains to max k size
    KthLargest(int k, vector<int>& nums) {
        this->size = k;
        for (const int &n : nums){
            values.push(n);
            if (values.size() > size){
                values.pop();
            }
        }
    }
    
    // Adding values works the same as the constructor
    int add(int val) {
        values.push(val);
        if (values.size() > size){
            values.pop();
        }
        return values.top();
    }
};