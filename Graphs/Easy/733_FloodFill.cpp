/* 
 * Problem: 733 
 * Name: Flood Fill
 * Difficulty: Easy
 * Topic: Graphs
 * Link: https://leetcode.com/problems/flood-fill/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      BFS (breadth first search) -> Queue
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<vector<int>> floodFillBFS(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    if (oldColor == newColor) {return image;}
    queue<pair<int, int>> next;
    next.push({sr, sc});
    while(!next.empty()){
        auto p = next.front();
        next.pop();
        sr = p.first; sc = p.second;
        if (image[sr][sc] == oldColor){
            image[sr][sc] = newColor;
            if (sr > 0){next.push({sr-1, sc});}
            if (sc > 0){next.push({sr, sc-1});}
            if (sr < image.size() - 1){next.push({sr+1, sc});}
            if (sc < image[0].size() - 1){next.push({sr, sc+1});}
        }
    }
    return image;
}

//      DFS (depth first search) -> (Function Call) Stack
// Time Complexity: O(n)
// Space Complexity: O(n)
void floodFillHelper(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor);
vector<vector<int>> floodFillDFS(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    if (oldColor != newColor){
        floodFillHelper(image, sr, sc, newColor, oldColor);
    }
    return image;
}

void floodFillHelper(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor){
    if (image[sr][sc] != oldColor){return;}
    image[sr][sc] = newColor;
    if (sr > 0){floodFillHelper(image, sr-1, sc, newColor, oldColor);}
    if (sc > 0){floodFillHelper(image, sr, sc-1, newColor, oldColor);}
    if (sr < image.size() - 1){floodFillHelper(image, sr+1, sc, newColor, oldColor);}
    if (sc < image[0].size() - 1){floodFillHelper(image, sr, sc+1, newColor, oldColor);}
}