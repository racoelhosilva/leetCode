/* 
 * Problem: 101 
 * Name: Symmetric Tree
 * Difficulty: Easy
 * Topic: Binary Trees
 * Link: https://leetcode.com/problems/symmetric-tree/
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

//      Recursive Solution
// Time Complexity: O(n)
// Space Complexity: O(1)
bool isSymmetricHelper(TreeNode *left, TreeNode* right);
bool isSymmetricRecursive(TreeNode* root) {
    if (root == nullptr) { return true;}
    return isSymmetricHelper(root->left, root->right);     
}
bool isSymmetricHelper(TreeNode *left, TreeNode* right){
    if (left == right) { return true;}
    if (left == nullptr || right == nullptr) { return false;}
    return left->val == right->val &&
            isSymmetricHelper(left->left, right->right) &&
            isSymmetricHelper(left->right, right->left);
}

//      Iterative Solution (BFS)
// Time Complexity: O(n)
// Space Complexity: O(n)
bool isSymmetricBFS(TreeNode* root) {
    if (root == nullptr) { return true;}
    queue<TreeNode *> q;
    q.push(root->left);   
    q.push(root->right);
    while(!q.empty()){
        TreeNode *l = q.front(); q.pop();
        TreeNode *r = q.front(); q.pop();
        if (l == r) { continue;}
        else if (l == nullptr || r == nullptr) { return false;}
        else if (l->val != r->val) { return false;}
        else {
            q.push(l->left);
            q.push(r->right);
            q.push(l->right);
            q.push(r->left);
        }
    }
    return true;
}

//      Iterative Solution (DFS)
// Time Complexity: O(n)
// Space Complexity: O(n)
bool isSymmetricDFS(TreeNode* root) {
    if (root == nullptr) { return true;}
    stack<TreeNode *> s;
    s.push(root->left);   
    s.push(root->right);
    while(!s.empty()){
        TreeNode *l = s.top(); s.pop();
        TreeNode *r = s.top(); s.pop();
        if (l == r) { continue;}
        else if (l == nullptr || r == nullptr) { return false;}
        else if (l->val != r->val) { return false;}
        else {
            s.push(l->left);
            s.push(r->right);
            s.push(l->right);
            s.push(r->left);
        }
    }
    return true;
}