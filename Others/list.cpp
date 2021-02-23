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

bool hasCycle(ListNode *head) {
    if (!head || !head->next) return false;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast) {
        slow = slow->next;
        if (fast->next) fast = fast->next->next;
        else return false;
        if (slow == fast) return true;
    }
    return false;
}

ListNode* mid(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode* reverse(ListNode* head) {
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
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    ListNode* cur = head;
    ListNode* MidNode = mid(head);
    ListNode* nhead = reverse(head);
    while (cur && nhead) {
        if (cur->val != nhead->val) return false;
        else {
            cur = cur->next;
            nhead = nhead->next;
        }
    }
    return true;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    ListNode* nhead = new ListNode(0);
    ListNode* cur = nhead;
    ListNode* n1 = l1;
    ListNode* n2 = l2;
    int flag = 0;
    while (n1 || n2) {
        int num1 = n1 == nullptr ? 0 : n1->val;
        int num2 = n2 == nullptr ? 0 : n2->val;
        int cur_val = (num1 + num2 + flag) % 10;
        flag = (num1 + num2 + flag) / 10;
        n1 = n1? n1->next : nullptr;
        n2 = n2? n2->next : nullptr;
        cur->next = new ListNode(cur_val);
        cur = cur->next;
    }
    if (flag) cur->next = new ListNode(1);
    return nhead->next;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    ListNode* nhead = new ListNode(0);
    ListNode* cur = nhead;
    ListNode* n1 = l1;
    ListNode* n2 = l2;
    while (n1 && n2) {
        if (n1->val <= n2->val) {
            cur->next = new ListNode(n1->val);
            n1 = n1->next;
        }
        else {
            cur->next = new ListNode(n2->val);
            n2 = n2->next;
        }
        cur = cur->next;
    }
    if (n1) cur->next = n1;
    if (n2) cur->next = n2;
    return nhead->next;
}