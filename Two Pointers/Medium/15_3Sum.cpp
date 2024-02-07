/* 
 * Problem: 15 
 * Name: 3Sum
 * Difficulty: Medium
 * Topic: Two Pointers
 * Link: https://leetcode.com/problems/3sum
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Reduction to Two Sum Sorted Array + Hash Map
// Time Complexity: O(n²)
// Space Complexity: O(n)
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.size() < 3) {return result;}
    sort(nums.begin(), nums.end());
    if (nums[0] > 0) {return result;}
    unordered_map<int, int> valueIndex;
    
    for (int i = 0; i < nums.size(); i++)
        valueIndex[nums[i]] = i;
    
    for (int i = 0; i < nums.size() - 2; i++) {
        if (nums[i] > 0){
            break;
        }
        if (i != 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        for (int j = i + 1; j < nums.size() - 1; j++) {
            
            if (j != i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            
            int target = -(nums[i] + nums[j]);
            if (valueIndex.find(target) != valueIndex.end() && valueIndex[target] > j){
                result.push_back({nums[i], nums[j], target});
            }
        }
    }
    return result;
}

//      Reduction to Two Sum Sorted Array + Two Pointers
// Time Complexity: O(n²)
// Space Complexity: O(n)
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.size() < 3) {return result;}
    sort(nums.begin(), nums.end());
    if (nums[0] > 0) {return result;}

    for (int idx = 0; idx < nums.size()-2; idx++){
        if (nums[idx] > 0) {
            break;
        }
        if (idx != 0 && nums[idx] == nums[idx-1]){
            continue;
        }

        int l = idx+1, r = int(nums.size())-1;
        while (l < r){
            int sum = nums[idx] + nums[r] + nums[l];
            if (sum < 0){
                l++;
            }
            else if (sum > 0){
                r--;
            }
            else {
                result.push_back({nums[idx], nums[l], nums[r]});
                while(l < r && nums[l] == nums[l+1]){
                    l++;
                }
                l++;
                while(l < r && nums[r] == nums[r-1]){
                    r--;
                }
                r--;
            }
        }
    }
    return result;
}