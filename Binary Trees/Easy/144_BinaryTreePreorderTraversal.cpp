/* 
 * Problem: 144 
 * Name: Binary Tree Preorder Traversal
 * Difficulty: Easy
 * Topic: Binary Trees
 * Link: https://leetcode.com/problems/binary-tree-preorder-traversal
 */
 
#include <bits/stdc++.h>
#include <cstddef>
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

//      Stack
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> preorderTraversal(TreeNode* root) {
    if (root == nullptr) {return {};}
    vector<int> result;
    stack<TreeNode*> remaining;
    remaining.push(root);

    while (!remaining.empty()) {
        TreeNode *current = remaining.top();
        remaining.pop();
        result.push_back(current->val);

        if (current->right != nullptr) {remaining.push(current->right);}
        if (current->left != nullptr) {remaining.push(current->left);}
    }
    return result;
}

//      Call Stack
// Time Complexity: O(n)
// Space Complexity: O(n)
void preorderHelper(TreeNode* node, vector<int>& result);
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    preorderHelper(root, result);
    return result;
}
void preorderHelper(TreeNode* node, vector<int>& result){
    if (node == nullptr) {return;}
    result.push_back(node->val),
    preorderHelper(node->left, result);
    preorderHelper(node->right, result);
}
