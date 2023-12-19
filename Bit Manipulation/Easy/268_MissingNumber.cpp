/* 
 * Problem: 268 
 * Name: Missing Number
 * Difficulty: Easy
 * Topic: Bit Manipulation
 * Link: https://leetcode.com/problems/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Binary Search
/* When the n numbers are ordered, if the number at index i is equal to i,
 * then all number before it are in the correct positions, so the lowerBound
 * can be incremented; otherwise, there is a number missing before i, and the
 * upperBound should be decremented
 * Eventually they will converge to the index/value missing and return it
 */
// Time Complexity: O(n log n)
// Space Complexity: O(1)
int missingNumberSort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int lowerBound = 0;
    int upperBound = nums.size();
    while (lowerBound < upperBound){
        int midValue = lowerBound + (upperBound - lowerBound) / 2;
        if (nums[midValue] > midValue){
            upperBound = midValue;
        }
        else {
            lowerBound = midValue + 1;
        }
    }
    return lowerBound;
}

//      Sum of the sequence
/* Using the gaussian formula for the sum of the first n values of a sequence
 * we can obtain the total sum of the sequence and iterate through the loop 
 * subtracting the numbers that are there, the result will be the missing number 
 */
// Time Complexity: O(n)
// Space Complexity: O(1)
int missingNumberMath(vector<int>& nums) {
    int result = ((nums.size()+1) * (0 + nums.size())) / 2;
    for (const int &n : nums){
        result -= n;
    }
    return result;
}

//      Bit Manipulation (XOR)
// Time Complexity: O(n)
// Space Complexity: O(1)
int missingNumber(vector<int>& nums) {
    int result = nums.size();
    for (int idx = 0; idx < nums.size(); idx++){
        result ^= idx;
        result ^= nums[idx];
    }
    return result;
}