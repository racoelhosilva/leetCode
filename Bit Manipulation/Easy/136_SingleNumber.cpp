/* 
 * Problem: 136 
 * Name: Single Number
 * Difficulty: Easy
 * Topic: Bit Manipulation
 * Link: https://leetcode.com/problems/single-number/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Sorting
// Time Complexity: O(n log n)
// Space Complexity: O(1)
int singleNumberSort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int idx = 1; idx < nums.size(); idx+=2){
        if (nums[idx] != nums[idx-1]){
            return nums[idx-1];
        }
    }
    return nums[nums.size()-1];
}

//      Set and Sum
// Time Complexity: O(n)
// Space Complexity: O(n)
int singleNumberSet(vector<int>& nums) {
    int sum = 0;
    unordered_set<int> freq;
    for (int idx = 1; idx < nums.size(); idx+=2){
        if (freq.count(nums[idx]) == 0){
            sum += nums[idx];
            freq.insert(nums[idx]);
        }
        else {
            sum -= nums[idx]; 
        }
    }
    return sum;
}

//      Bitwise XOR
// Time Complexity: O(n)
// Space Complexity: O(1)
int singleNumber(vector<int>& nums){
    int result = 0;
    for (const int& n : nums){
        result ^= n;
    }
    return result;
}
