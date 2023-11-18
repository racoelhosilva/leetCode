#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> passed;
    for (int n : nums){
        if (passed.count(n) == 0){
            passed.insert(n);
        }
        else {
            return true;
        }
    }
    return false;
}