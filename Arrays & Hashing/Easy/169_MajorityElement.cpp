/* 
 * Problem: 169 
 * Name: Majority Element
 * Difficulty: Easy
 * Topic: Arrays & Hashing
 * Link: https://leetcode.com/problems/majority-element/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Sort Array
// Time Complexity: O(n log n)
// Space Complexity: O(1)
int majorityElementSort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
}

//      Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)
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

//      Boyer-Moore Majority Voting Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)
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