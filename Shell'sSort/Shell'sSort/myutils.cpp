#include <iostream>
#include "myutils.h"

ListNode* arrToListNode(int arr[]) {
    ListNode *head = new ListNode(0), * p = head;
    for (int i = 1; i < 5; i++) {
        ListNode* temp = new ListNode(i);
        p->next = temp;
        p = p->next;
    }
    return head;
}