/* 
 * Problem: 141 
 * Name: Linked List Cycle
 * Difficulty: Easy
 * Topic: Linked Lists
 * Link: https://leetcode.com/problems/
 */
 
#include <bits/stdc++.h>
using namespace std;

// List Node Implementation
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//      Hash Set Approach
// Time Complexity: O(n)
// Space Complexity: O(n)
bool hasCycleHashSet(ListNode *head) {
    set<ListNode*> visited;
    while (head != nullptr){
        if (visited.count(head) != 0) {return true;}
        visited.insert(head);
        head = head->next;
    }
    return false;
}

//      Floyd's Cycle Detection
// Time Complexity: O(n)
// Space Complexity: O(1)
bool hasCycleFloyd(ListNode *head){
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            return true;
        }
    }
    return false;
}