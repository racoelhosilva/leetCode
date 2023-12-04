#include<bits/stdc++.h>
using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> values;
    int size;

public:
    KthLargest(int k, vector<int>& nums) {
        this->size = k;
        for (const int &n : nums){
            values.push(n);
            if (values.size() > size){
                values.pop();
            }
        }
    }
    
    int add(int val) {
        values.push(val);
        if (values.size() > size){
            values.pop();
        }
        return values.top();
    }
};
