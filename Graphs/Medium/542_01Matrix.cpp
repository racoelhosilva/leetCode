/* 
 * Problem: 542 
 * Name: 01 Matrix
 * Difficulty: Medium
 * Topic: Graphs
 * Link: https://leetcode.com/problems/01-matrix
 */
 
#include <bits/stdc++.h>
using namespace std;

//      BFS (breadth first search)
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
vector<vector<int>> updateMatrixBFS(vector<vector<int>>& mat) {
    vector<int> ADJACENT = {0, 1, 0, -1, 0};
    queue<pair<int, int>> next;

    for (int row = 0; row < mat.size(); row++){
        for (int col = 0; col < mat[row].size(); col++){
            if (mat[row][col] == 0) {
                next.push({row, col});
            }
            else {
                mat[row][col] = -1;
            }
        }
    }
    while (!next.empty()) {
        auto [row, col] = next.front();
        next.pop();

        for (int i = 0; i < 4; i++){
            int newRow = row + ADJACENT[i], newCol = col + ADJACENT[i+1]; 
            if (newRow < 0 || newRow >= mat.size() || newCol < 0 || newCol >= mat[0].size() || mat[newRow][newCol] != -1){ 
                continue; 
            }
            mat[newRow][newCol] = mat[row][col] + 1;
            next.push({newRow, newCol});
        }
    }
    return mat;
}

//      Dynamic Programming (restrict checks)
// Time Complexity: O(m*n)
// Space Complexity: O(1)
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int rows = mat.size(), cols = mat[0].size();
    int maxDistance = rows + cols; // longest possible path (diameter)

    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            if (mat[r][c] == 0) { continue; }
            int top = maxDistance, right = maxDistance;
            if (r - 1 >= 0) { top = mat[r-1][c]; }
            if (c - 1 >= 0) { right = mat[r][c-1]; }
            mat[r][c] = min(top, right) + 1;
        }
    }
    for (int r = rows - 1; r >= 0; r--){
        for (int c = cols - 1; c >= 0; c--){
            if (mat[r][c] == 0) { continue; }
            int down = maxDistance, left = maxDistance;
            if (r + 1 < rows) { down = mat[r+1][c]; }
            if (c + 1 < cols) { left = mat[r][c+1]; }
            mat[r][c] = min(mat[r][c], min(down, left) + 1);
        }
    }
    return mat;
}