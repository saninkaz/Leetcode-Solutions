/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int n1 = 0, n2 = 0, n3 = 0;
    int carry = 0;
    struct ListNode* root = malloc(sizeof(struct ListNode));
    struct ListNode* current = root;
    while (l1 != NULL && l2 != NULL) {
        n1 = l1->val + l2->val + carry;
        struct ListNode* nnode = malloc(sizeof(struct ListNode));
        nnode->val = n1 % 10;
        nnode->next = NULL;
        if (n1 >= 10) {
            carry = 1;
        } else
            carry = 0;
        l1 = l1->next;
        l2 = l2->next;
        current->next = nnode;
        current = nnode;
    }

    while (l1 != NULL) {
        struct ListNode* nnode = malloc(sizeof(struct ListNode));
        int n2 = (l1->val + carry);
        nnode->val = n2 % 10;
        nnode->next = NULL;
        if (n2 >= 10) {
            carry = 1;
        } else
            carry = 0;
        l1 = l1->next;
        current->next = nnode;
        current = nnode;
    }

    while (l2 != NULL) {
        struct ListNode* nnode = malloc(sizeof(struct ListNode));
        int n3 = (l2->val + carry);
        nnode->val = n3 % 10;
        nnode->next = NULL;
        if (n3 >= 10) {
            carry = 1;
        } else
            carry = 0;
        l2 = l2->next;
        current->next = nnode;
        current = nnode;
    }

    if (carry == 1) {
        struct ListNode* nnode = malloc(sizeof(struct ListNode));
        nnode->val = 1;
        nnode->next = NULL;
        current->next = nnode;
        current = nnode;
    }

    return root->next;
}