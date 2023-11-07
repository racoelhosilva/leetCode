#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeTwoListsIterative(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr){ return list2;}
    if (list2 == nullptr){ return list1;}


    ListNode* start = nullptr;
    if (list1->val <= list2->val) {
        start = list1;
        list1 = list1->next;
    } else {
        start = list2;
        list2 = list2->next;            
    }

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

    if (list1 == nullptr){
            current->next = list2;
    }
    else if (list2 == nullptr){
        current->next = list1;
    }
    return start;
}


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