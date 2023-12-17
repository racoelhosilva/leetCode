/* 
 * Problem: 206 
 * Name: Reverse Linked List
 * Difficulty: Easy
 * Topic: Linked Lists
 * Link: https://leetcode.com/problems/reverse-linked-list/
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

//      Iterative Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {return head;}
    
    ListNode *previousNode = nullptr, *nextNode;
    while(nextNode != nullptr){        
        nextNode = head->next;

        head->next = previousNode;
        previousNode = head;
        head = nextNode;
    } 
    return previousNode;
}