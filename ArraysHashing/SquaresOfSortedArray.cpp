#include<bits/stdc++.h>
using namespace std;

// O(nlog n)
vector<int> sortedSquares(vector<int>& nums) {
    for (int idx = 0; idx < nums.size(); idx++){
        nums[idx] = nums[idx] * nums[idx];    
    }
    sort(nums.begin(), nums.end());
    return nums;
}

// O(n)
vector<int> sortedSquares(vector<int>& nums) {
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
