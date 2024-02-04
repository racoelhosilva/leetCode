/* 
 * Problem: 167 
 * Name: Two Sum II - Sorted Input Array
 * Difficulty: Medium
 * Topic: Two Pointers
 * Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Binary Search
// Time Complexity: O(n log n)
// Space Complexity: O(1)
vector<int> twoSumBS(vector<int>& numbers, int target) {
    for (int i = 0; i < numbers.size(); i++){
        int complement = target - numbers[i];
        int lowerBound = i + 1;
        int upperBound = numbers.size() - 1;
        while (lowerBound <= upperBound){
            int midValue = lowerBound + (upperBound - lowerBound) / 2;

            if (numbers[midValue] < complement){
                lowerBound = midValue + 1;
            }
            else if (numbers[midValue] > complement){
                upperBound = midValue - 1;
            }
            else {
                return {i+1, midValue+1};
            }
        }
    }
    return {};
}

//      Two-Pointer Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0, r = numbers.size() - 1;
    while (l < r) {
        if (numbers[l] + numbers[r] == target){
            return {l+1, r+1};
        }
        else if (numbers[l] + numbers[r] > target) {
            r--;
        }
        else {
            l++;
        }
    }
    return {};
}