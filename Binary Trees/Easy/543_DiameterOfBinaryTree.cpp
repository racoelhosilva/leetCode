/* 
 * Problem: 543 
 * Name: Diameter Of Binary Tree
 * Difficulty: Easy
 * Topic: Binary Trees
 * Link: https://leetcode.com/problems/diameter-of-binary-tree/
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

//      Recursive Approach
// Time Complexity:
// Space Complexity: O(1)
int diameterHeightHelper(TreeNode* root, int &diameter);
int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        diameterHeightHelper(root, diameter);
        return diameter;
}
int diameterHeightHelper(TreeNode* root, int &diameter) {
    if (root == nullptr) { return 0; }
    
    // Get the maximum height for each side
    int leftHeight = diameterHeightHelper(root->left, diameter);
    int rightHeight = diameterHeightHelper(root->right, diameter);

    // Update the diameter if necessary
    diameter = max(diameter, leftHeight+rightHeight);

    // Return the height of the current node
    return max(leftHeight, rightHeight) + 1;
}