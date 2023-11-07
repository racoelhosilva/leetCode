#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


bool hasCycleHashSet(ListNode *head) {
    set<ListNode*> visited;
    while (head != nullptr){
        if (visited.count(head) != 0) {return true;}
        visited.insert(head);
        head = head->next;
    }
    return false;
}

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