/* 
 * Problem: 234 
 * Name: Palindrome Linked List
 * Difficulty: Easy
 * Topic: Linked Lists
 * Link: https://leetcode.com/problems/palindrome-linked-list/
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

//      Floyd, reverse, compare
// Time Complexity: O(n)
// Space Complexity: O(!)
bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr){ return true;}
    
    // Floyd to find middle of list
    ListNode *slow = head, *fast=head;
    while (fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }

    // Reverse the second half of the list
    ListNode *curr = slow->next, *prev = slow;
    prev->next = nullptr; 
    while (curr != nullptr){
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    // Traverse both ends and meet in the middle
    ListNode *left = head, *right=prev;
    while (right != nullptr){
        if (left->val != right->val) {
            return false;
        }
        left = left->next;
        right = right->next;
    }
    return true;
}