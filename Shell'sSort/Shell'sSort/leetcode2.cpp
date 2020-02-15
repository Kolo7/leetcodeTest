#include <iostream>
#include "myutils.h"
#include <vector>
#include <algorithm>

ListNode* sortList(ListNode* head) {
    ListNode* p = head;
    std::vector<int> ve;
    while (p != NULL) {
        ve.push_back(p->val);
        p = p->next;
    }
    sort(ve.begin(), ve.end(), std::greater<int>());
    p = head;
    for (std::vector<int>::iterator i = ve.begin(); i != ve.end(); i++) {
        p->val = *i;
        p = p->next;
    }
    return head;
}
