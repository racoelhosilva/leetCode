#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Using only one function
TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.size() == 0) { return nullptr;}
    if (nums.size() == 1) { return new TreeNode(nums[0]);}
    int middleIdx = nums.size() / 2;
    TreeNode *root = new TreeNode(nums[middleIdx]);
    vector<int> leftNums = {nums.begin(), nums.begin() + middleIdx};
    vector<int> rightNums = {nums.begin() + middleIdx + 1, nums.end()};
    root->left = sortedArrayToBST(leftNums);
    root->right = sortedArrayToBST(rightNums);
    return root;
}

// Using an helper function
// This solution uses less memory because it doesn't create the subvectors
TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int left, int right) {
    if (left > right) { return nullptr;}
    int middleIdx = left + (right - left) / 2;
    TreeNode *root = new TreeNode(nums[middleIdx]);
    root->left = sortedArrayToBSTHelper(nums, left, middleIdx-1);
    root->right = sortedArrayToBSTHelper(nums, middleIdx+1, right);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBSTHelper(nums, 0, nums.size()-1);
}
