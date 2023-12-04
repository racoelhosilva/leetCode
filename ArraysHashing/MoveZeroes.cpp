#include<bits/stdc++.h>
using namespace std;

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