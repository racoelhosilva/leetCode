/* 
 * Problem: 226 
 * Name: Invert Binary Tree
 * Difficulty: Easy
 * Topic: Binary Trees
 * Link: https://leetcode.com/problems/invert-binary-tree/
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
// Time Complexity: O(n)
// Space Complexity: O(1)
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr){return root;}

    invertTree(root->left);
    invertTree(root->right);
    swap(root->left, root->right);
    return root;
}