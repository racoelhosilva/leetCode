/* 
 * Problem: 57 
 * Name: Insert Interval
 * Difficulty: Medium
 * Topic: Intervals
 * Link: https://leetcode.com/problems/insert-interval/
 */
 
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

//  Initial Solution (not focused on the global cases)
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    bool hasInserted = false;
    for (const vector<int>& interval : intervals){
        if (!hasInserted){
            if (interval[1] < newInterval[0]) {
                result.push_back(interval);
            }
            else if (interval[0] < newInterval[0]) {
                result.push_back(interval);
                result.back()[1] = max(interval[1], newInterval[1]);
                hasInserted = true;
            }
            else if (interval[0] <= newInterval[1]) {
                result.push_back(newInterval);
                result.back()[1] = max(interval[1], newInterval[1]);
                hasInserted = true;
            }
            else {
                result.push_back(newInterval);
                result.push_back(interval);
                hasInserted = true;
            }
        }
        else {
            if (result.back()[1] < interval[0]){
                result.push_back(interval);
            }
            else {
                result.back()[1] = max(interval[1], result.back()[1]);
            }
        }
    }
    if (!hasInserted){
        result.push_back(newInterval);
        hasInserted = true;
    }
    return result;
}

//  Optimized Solution (3 main cases)
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int i = 0;
    
    while (i < intervals.size() && intervals[i][1] < newInterval[0]){
        result.push_back(intervals[i]);
        i++;
    }

    while (i < intervals.size() && intervals[i][0] <= newInterval[1]){
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
        i++;
    }
    result.push_back(newInterval);

    while (i < intervals.size()){
        result.push_back(intervals[i]);
        i++;
    }

    return result;
}
