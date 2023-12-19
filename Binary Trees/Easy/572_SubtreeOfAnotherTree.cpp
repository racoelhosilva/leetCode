/* 
 * Problem: 572 
 * Name: Subtree Of Another Tree
 * Difficulty: Easy
 * Topic: Binary Trees
 * Link: https://leetcode.com/problems/subtree-of-another-tree/
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
// Time Complexity: O(n²)
// Space Complexity: O(1)
bool isSameTree(TreeNode* p, TreeNode* q);
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == subRoot) {return true;}
    if (root == nullptr || subRoot == nullptr) {return false;}
    return  isSameTree(root, subRoot) || 
            isSubtree(root->left, subRoot) || 
            isSubtree(root->right, subRoot);
}
// Auxiliar function from problem "SameTree"
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == q){ return true;}
    else if (p == NULL || q == NULL){ return false;}
    else if (p->val != q->val) {return false;}
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
