/* 
 * Problem: 102 
 * Name: Binary Tree Level Order Traversal
 * Difficulty: Medium
 * Topic: Binary Trees
 * Link: https://leetcode.com/problems/binary-tree-level-order-traversal
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

//      First BFS
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) {return {};}
    queue<pair<TreeNode*, int>> remaining;
    int currentLevel = 0;
    remaining.push({root, currentLevel});

    vector<vector<int>> result;
    vector<int> levelValues;

    while (!remaining.empty()) {
        TreeNode* current = remaining.front().first;
        int level = remaining.front().second;
        remaining.pop();

        if (level != currentLevel){
            result.push_back(levelValues);
            levelValues.clear();
            currentLevel++;
        }
        levelValues.push_back(current->val);

        if (current->left != nullptr){
            remaining.push({current->left, level + 1});
        }
        if (current->right != nullptr){
            remaining.push({current->right, level + 1});
        }

    }
    result.push_back(levelValues);
    return result;
}

//      Second BFS (Improved)
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) {return {};}

    queue<TreeNode*> remaining;
    remaining.push(root);

    vector<vector<int>> result;

    while (!remaining.empty()) {
        int size = remaining.size();
        vector<int> level;
        for (int _ = 0; _ < size; _++){
            TreeNode* current = remaining.front();
            remaining.pop();
            level.push_back(current->val);
            if (current->left != nullptr) {remaining.push(current->left);}
            if (current->right != nullptr) {remaining.push(current->right);}
        }
        result.push_back(level);
    }
    return result;
}