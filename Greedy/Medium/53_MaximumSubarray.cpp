/* 
 * Problem: 53 
 * Name: Maximum Subarray
 * Difficulty: Medium
 * Topic: Greedy
 * Link: https://leetcode.com/problems/maximum-subarray/
 */
 
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

//      Divide and Conquer
// Time Complexity: O(n log n)
// Space Complexity: O(1)
int maxSubArrayDCHelper(vector<int>& nums, int left, int right);
int maxSubArrayDC(vector<int>& nums){
    return maxSubArrayDCHelper(nums, 0, nums.size()-1);
}
int maxSubArrayDCHelper(vector<int>& nums, int left, int right){
    if (left == right) {return nums[left];}
    int mid = left + (right - left) / 2;
    int currentSum = 0;
    int leftSum = 0;
    for (int idx = mid - 1; idx >= left; idx--){
        currentSum += nums[idx];
        if (currentSum > leftSum){
            leftSum = currentSum;
        }
    }
    currentSum = 0;
    int rightSum = 0;
    for (int idx = mid + 1; idx <= right; idx++){
        currentSum += nums[idx];
        if (currentSum > rightSum){
            rightSum = currentSum;
        }
    }
    return max(max(maxSubArrayDCHelper(nums, left, mid-1), 
                      maxSubArrayDCHelper(nums, mid+1, right)),
               leftSum+nums[mid]+rightSum);
}

//      Kadane's Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)
int maxSubArrayKadane(vector<int>& nums) {
    if (nums.empty()) {return 0;}
    int maxSum = nums[0];
    int currentSum = 0;
    for (int cur = 0; cur < nums.size(); cur++){    
        currentSum += nums[cur];
        if (currentSum > maxSum){
            maxSum = currentSum;
        }
        if (currentSum < 0) {
            currentSum = 0;
        }
    }
    return maxSum;
}