/* 
 * Problem: 235 
 * Name: Lowest Common Ancestor BST
 * Difficulty: Medium
 * Topic: Binary Trees
 * Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 */
 
#include <bits/stdc++.h>
using namespace std;

// Tree Node Implementation
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//      Recursive Approach
// Time Complexity: O(log n)
// Space Complexity: O(1)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) {return nullptr;}
    if (root == p || root == q){return root;}

    if (root->val > p->val && root->val > q->val){ 
        return lowestCommonAncestor(root->left, p, q);
    }
    if (root->val < p->val && root->val < q->val){ 
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}