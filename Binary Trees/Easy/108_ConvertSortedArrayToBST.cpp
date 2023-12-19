/* 
 * Problem: 108 
 * Name: Convert Sorted Array To BST
 * Difficulty: Easy
 * Topic: Binary Trees
 * Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 */
 
#include <bits/stdc++.h>
using namespace std;

// Tree Node Implementation
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//      Using only one function
// Time Complexity: O(n)
// Space Complexity: O(n)
TreeNode* sortedArrayToBSTOne(vector<int>& nums) {
    if (nums.size() == 0) { return nullptr;}
    if (nums.size() == 1) { return new TreeNode(nums[0]);}
    int middleIdx = nums.size() / 2;
    TreeNode *root = new TreeNode(nums[middleIdx]);
    vector<int> leftNums = {nums.begin(), nums.begin() + middleIdx};
    vector<int> rightNums = {nums.begin() + middleIdx + 1, nums.end()};
    root->left = sortedArrayToBSTOne(leftNums);
    root->right = sortedArrayToBSTOne(rightNums);
    return root;
}

//      Using an helper function
// Time Complexity: O(n)
// Space Complexity: O(n)
// This solution uses less memory because it doesn't create the subvectors
TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int left, int right);
TreeNode* sortedArrayToBSTTwo(vector<int>& nums) {
    return sortedArrayToBSTHelper(nums, 0, nums.size()-1);
}
TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int left, int right) {
    if (left > right) { return nullptr;}
    int middleIdx = left + (right - left) / 2;
    TreeNode *root = new TreeNode(nums[middleIdx]);
    root->left = sortedArrayToBSTHelper(nums, left, middleIdx-1);
    root->right = sortedArrayToBSTHelper(nums, middleIdx+1, right);
    return root;
}