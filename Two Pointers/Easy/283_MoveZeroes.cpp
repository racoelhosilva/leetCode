/* 
 * Problem: 283 
 * Name: Move Zeroes
 * Difficulty: Easy
 * Topic: Two Pointers
 * Link: https://leetcode.com/problems/move-zeroes/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Two-Pointer Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
void moveZeroes(vector<int>& nums) {
    int slow = 0;
    int fast = 0;
    while (fast < nums.size()){
        if (nums[fast] != 0){
            swap(nums[fast], nums[slow]);
            slow++;
        }
        fast++;
    }
}