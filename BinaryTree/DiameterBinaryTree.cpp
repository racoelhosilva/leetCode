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

int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        diameterHeightHelper(root, diameter);
        return diameter;
}
    
int diameterHeightHelper(TreeNode* root, int &diameter) {
    if (root == nullptr) { return 0; }
    
    int leftHeight = diameterHeightHelper(root->left, diameter);
    int rightHeight = diameterHeightHelper(root->right, diameter);

    diameter = max(diameter, leftHeight+rightHeight);

    return max(leftHeight, rightHeight) + 1;
}
