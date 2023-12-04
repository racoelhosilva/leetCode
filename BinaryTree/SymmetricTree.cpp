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

// Recursive Solution
bool isSymmetricHelper(TreeNode *left, TreeNode* right){
    if (left == right) { return true;}
    if (left == nullptr || right == nullptr) { return false;}
    return left->val == right->val &&
            isSymmetricHelper(left->left, right->right) &&
            isSymmetricHelper(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if (root == nullptr) { return true;}
    return isSymmetricHelper(root->left, root->right);     
}

// Iterative Solution (BFS)
bool isSymmetric(TreeNode* root) {
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

// Iterative Solution (DFS)
bool isSymmetric(TreeNode* root) {
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