/* 
 * Problem: 973 
 * Name: K Closest Point To Origin
 * Difficulty: Medium
 * Topic: Priority Queue
 * Link: https://leetcode.com/problems/k-closest-points-to-origin/
 */
 
#include <bits/stdc++.h>
using namespace std;

//      Partial Sort Solution
// Time Complexity: O(n log K)
// Space Complexity: O(1)
vector<vector<int>> kClosestPS(vector<vector<int>>& points, int K) {
    partial_sort(points.begin(), points.begin() + K, points.end(), 
        [](vector<int>& p, vector<int>& q) { return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];});
    return vector<vector<int>>(points.begin(), points.begin() + K);
}

//      Nth_Element Solution
// Time Complexity: O(n log K)
// Space Complexity: O(1)
vector<vector<int>> kClosestNE(vector<vector<int>>& points, int K) {
    nth_element(points.begin(), points.begin() + K - 1, points.end(), 
        [](vector<int>& p, vector<int>& q) {return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];});
    return vector<vector<int>>(points.begin(), points.begin() + K);
}

//      Min Heap of Points
// Time Complexity: O(n + k log n)
// Space Complexity: O(n)
struct MinDistanceComparator {
    bool operator()(vector<int>& p1, vector<int>& p2){
        return p1[0] * p1[0] + p1[1] * p1[1] > p2[0] * p2[0] + p2[1] * p2[1];
    }
};

vector<vector<int>> kClosestPQP(vector<vector<int>>& points, int k) {
    priority_queue<vector<int>, vector<vector<int>>, MinDistanceComparator> ordered(points.begin(), points.end());
    vector<vector<int>> result;
    while (k--){
        result.push_back(ordered.top());
        ordered.pop();
    }
    return result;
}

//      Min Heap of Indexes
// Time Complexity: O(n + k log n)
// Space Complexity: O(n)
vector<vector<int>> kClosestPQI(vector<vector<int>>& points, int k) {
    priority_queue<pair<double, int>, vector<pair<double,int>>, std::greater<pair<double, int>>> ordered;
    for (int idx = 0; idx < points.size(); idx++){
        ordered.push({points[idx][0] * points[idx][0] + points[idx][1] * points[idx][1], idx});        
    }
    
    vector<vector<int>> result;
    while (k--){
        result.push_back(points[ordered.top().second]);
        ordered.pop();
    }
    return result;
}
