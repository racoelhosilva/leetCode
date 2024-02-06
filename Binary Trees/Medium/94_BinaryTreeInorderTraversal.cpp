/* 
 * Problem: 94 
 * Name: Binary Tree Inorder Traversal
 * Difficulty: Medium
 * Topic: Binary Trees
 * Link: https://leetcode.com/problems/binary-tree-inorder-traversal
 */
 
#include <bits/stdc++.h>
#include <cstddef>
#include <vector>
using namespace std;

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
vector<int> inorderTraversal(TreeNode* root) {
    if (root == nullptr) {return {};}
    vector<int> result;
    stack<TreeNode*> remaining;       
    TreeNode* current = root;

    while (!remaining.empty() || current != nullptr) {
        while (current != nullptr) {
            remaining.push(current);
            current = current->left;
        }
        current = remaining.top();
        remaining.pop();
        result.push_back(current->val);
        current = current->right;
    }
    return result;
}

//      Call Stack
// Time Complexity: O(n)
// Space Complexity: O(n)
void inorderHelper(TreeNode* node, vector<int>& result);
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorderHelper(root, result);
    return result;
}
void inorderHelper(TreeNode* node, vector<int>& result){
    if (node == nullptr) {return;}
    inorderHelper(node->left, result);
    result.push_back(node->val),
    inorderHelper(node->right, result);
}

//      Morris Traversal
// Time Complexity: O(n)
// Space Complexity: O(1)
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> nodes;
    while (root != nullptr) {
        if (root -> left != nullptr) {
            TreeNode* pre = root -> left;
            while (pre->right != nullptr && pre->right != root) {
                pre = pre -> right;
            }
            if (pre -> right == nullptr) {
                pre -> right = root;
                root = root -> left;
            } else {
                pre -> right = NULL;
                nodes.push_back(root -> val);
                root = root -> right;
            }
        } else {
            nodes.push_back(root -> val);
            root = root -> right;
        }
    }
    return nodes;
}