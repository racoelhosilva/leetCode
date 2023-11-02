#include<bits/stdc++.h>
using namespace std;

//  Brute-Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
vector<int> twoSumBruteForce(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++){
        for (int j = i+1; j < nums.size(); j++){
            if (nums[i] + nums[j] == target){
                return {i, j};
            }
        }
    }
    return;
}

//  Two-Pass Hash Table
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> twoSumTwoPassHashTable(vector<int>& nums, int target) {
    map<int, int> valueIndex;
    for (int i = 0; i < nums.size(); i++){
        valueIndex[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++){
        int complement = target - nums[i];
        if (valueIndex.count(complement) == 1 && valueIndex[complement] != i){
            return {i, valueIndex[complement]};
        }
    }
    return;
}

//  One-Pass Hash Table
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> twoSumOnePassHashTable(vector<int>& nums, int target) {
    map<int, int> valueIndex;
    for (int i = 0; i < nums.size(); i++){
        int complement = target - nums[i];
        if (valueIndex.count(complement)){
            return {i, valueIndex[complement]};
        }
        valueIndex[nums[i]] = i;
    }
    return;
}