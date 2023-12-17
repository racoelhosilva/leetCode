/* 
 * Problem: 252 
 * Name: Meeting Rooms
 * Difficulty: Easy
 * Topic: Intervals
 * Link: https://leetcode.com/problems/meeting-rooms/
 */
 
#include <bits/stdc++.h>
using namespace std;

// Interval Implementation
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

//      Sort and Compare
// Time Complexity: O(n log n)
// Space Complexity: O(1)
bool canAttendMeetings(vector<Interval> &intervals) {
    sort(intervals.begin(), intervals.end(), 
    [](const Interval &i1, const Interval &i2){ return i1.start < i2.start;});

    for(int idx = 1; idx < intervals.size(); idx++){
        if (intervals[idx].start < intervals[idx-1].end){
            return false;
        }
    }
    return true;
}