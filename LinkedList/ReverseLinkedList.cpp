#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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