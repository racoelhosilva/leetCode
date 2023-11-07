#include<bits/stdc++.h>
using namespace std;

// Sort Array
int majorityElementSort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
}

// Hash Map
int majorityElementHash(vector<int>& nums) {
    if (nums.size() == 1) {return nums[0];}
    unordered_map<int, int> counter;   
    for (int n : nums){
        counter[n] += 1;
        if (counter.count(n) >= (nums.size()/2)){
            return n;
        }
        
    }
    return -1;
}

// Boyer-Moore Majority Voting Algorithm
int majorityElement(vector<int>& nums) {
    int counter = 0, candidate;
    for (int n : nums){
        if (counter == 0){
            candidate = n;
        }
        if (n == candidate){
            counter++;
        }
        else {
            counter--;
        }
    }
    return candidate;
}