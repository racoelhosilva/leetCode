/* 
 * Problem: 110 
 * Name: Balanced Binary Tree
 * Difficulty: Easy
 * Topic: Binary Trees
 * Link: https://leetcode.com/problems/balanced-binary-tree/
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
int heightCounter(TreeNode* root);
bool isBalanced(TreeNode* root) {
    if (root == nullptr) {return true;}
    return heightCounter(root) != -1;
}

int heightCounter(TreeNode* root) {
    if (root == nullptr) {return 0;} 

    int leftHeight = heightCounter(root->left);
    int rightHeight = heightCounter(root->right);

    if (abs(leftHeight - rightHeight) > 1 || leftHeight == -1 || rightHeight == -1){
        return -1;
    }

    return 1 + max(rightHeight, leftHeight);
}
