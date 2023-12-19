/* 
 * Problem: 977 
 * Name: Squares Of A Sorted Array
 * Difficulty: Easy
 * Topic: Two Pointers
 * Link: https://leetcode.com/problems/squares-of-a-sorted-array/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Naive Approach
// Time Complexity: O(n log n)
// Space Complexity: O(1)
vector<int> sortedSquaresSort(vector<int>& nums) {
    for (int idx = 0; idx < nums.size(); idx++){
        nums[idx] = nums[idx] * nums[idx];    
    }
    sort(nums.begin(), nums.end());
    return nums;
}

//      Two Pointer Approach
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> sortedSquaresTwoPointers(vector<int>& nums) {
    vector<int> result(nums.size());
    int left = 0;
    int right = nums.size()-1;
    while (left <= right){
        if (abs(nums[left]) > abs(nums[right])){
            result[right - left] = nums[left] * nums[left];
            left++;
        }
        else {
            result[right - left] = nums[right] * nums[right];
            right--;
        }
    }
    return result;
}
