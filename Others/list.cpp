ListNode* reverseList(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while (cur) {
        ListNode* temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}

ListNode* removeElements(ListNode* head, int val) {
    ListNode* nhead = new ListNode(0);
    nhead->next = head;
    ListNode* cur = nhead;
    while (cur->next) {
        if (cur->next->val == val) {
            cur->next = cur->next->next;
        }
        else cur = cur->next;
    }
    return nhead->next;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* a = headA;
    ListNode* b = headB;
    if (!a || !b) return nullptr;
    int flag = 0;
    while (a != b) {
        a = a->next == nullptr ? headB : a->next;
        b = b->next == nullptr ? headA : b->next;
        if (a == headB) flag++;
        if (flag > 2) return nullptr;
    }
    return a;
}