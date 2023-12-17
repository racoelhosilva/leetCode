/* 
 * Problem: 876 
 * Name: Middle Of Linked List
 * Difficulty: Easy
 * Topic: Linked Lists
 * Link: https://leetcode.com/problems/middle-of-the-linked-list/
 */
 
#include <bits/stdc++.h>
using namespace std;

// List Node Implementation
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//      Fast & Slow Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)
ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}