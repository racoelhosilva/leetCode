/* 
 * Problem: 145 
 * Name: Binary Tree Postorder Traversal
 * Difficulty: Easy
 * Topic: Binary Trees
 * Link: https://leetcode.com/problems/binary-tree-postorder-traversal
 */
 
#include <algorithm>
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

//      Reverse Preorder
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> postorderTraversal(TreeNode* root) {
    if (root == nullptr) {return {};}
    vector<int> result;
    stack<TreeNode*> remaining;
    remaining.push(root);

    while (!remaining.empty()) {
        TreeNode *current = remaining.top();
        remaining.pop();
        result.push_back(current->val);

        if (current->left != nullptr) {remaining.push(current->left);}
        if (current->right != nullptr) {remaining.push(current->right);}
    }
    reverse(result.begin(), result.end());
    return result;
}

//      Call Stack
// Time Complexity: O(n)
// Space Complexity: O(n)
void postorderHelper(TreeNode* node, vector<int>& result);
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    postorderHelper(root, result);
    return result;
}
void postorderHelper(TreeNode* node, vector<int>& result){
    if (node == nullptr) {return;}
    postorderHelper(node->left, result);
    postorderHelper(node->right, result);
    result.push_back(node->val);
}