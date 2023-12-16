/* 
 * Problem: 21 
 * Name: Merge Two Sorted Lists
 * Difficulty: Easy
 * Topic: Linked Lists
 * Link: https://leetcode.com/problems/merge-two-sorted-lists/
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

//      Merge Sorted (Iterative)
// Time Complexity: O(n)
// Space Complexity: O(1)
ListNode* mergeTwoListsIterative(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr){ return list2;}
    if (list2 == nullptr){ return list1;}

    // Start Node
    ListNode* start = nullptr;
    if (list1->val <= list2->val) {
        start = list1;
        list1 = list1->next;
    } else {
        start = list2;
        list2 = list2->next;            
    }

    // Middle Nodes
    ListNode* current = start;
    while(list1 != nullptr && list2 != nullptr){
        if (list1->val <= list2->val){
            current->next = list1;
            list1 = list1->next;
        }
        else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // Remaining Nodes
    if (list1 == nullptr){
            current->next = list2;
    }
    else if (list2 == nullptr){
        current->next = list1;
    }
    return start;
}

//      Merge Sorted (Recursive)
// Time Complexity: O(n)
// Space Complexity: O(1)
ListNode* mergeTwoListsRecursive(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr){ return list2;}
    if (list2 == nullptr){ return list1;}

    ListNode* start = nullptr;
    if (list1->val <= list2->val) {
        list1->next = mergeTwoListsRecursive(list1->next, list2);
        return list1;       
    } else {
        list2->next = mergeTwoListsRecursive(list1, list2->next);
        return list2;
    }
}