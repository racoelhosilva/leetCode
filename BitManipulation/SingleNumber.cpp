#include<bits/stdc++.h>
using namespace std;

// Sorting
int singleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int idx = 1; idx < nums.size(); idx+=2){
        if (nums[idx] != nums[idx-1]){
            return nums[idx-1];
        }
    }
    return nums[nums.size()-1];
}

// Bitwise XOR
int singleNumber(vector<int>& nums){
    int result = 0;
    for (const int& n : nums){
        result ^= n;
    }
    return result;
}