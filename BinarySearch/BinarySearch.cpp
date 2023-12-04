#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int lowerBound = 0;
    int upperBound = nums.size() - 1;

    while (lowerBound <= upperBound){
        int midValue = lowerBound + (upperBound - lowerBound) / 2;

        if (nums[midValue] < target){
            lowerBound = midValue + 1;
        }
        else if (target < nums[midValue]){
            upperBound = midValue - 1;
        }
        else {
            return midValue;
        }
    }
    return -1;
}