/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if(head == nullptr) return head;
        ListNode* headDummy = head -> next;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next;

        while(curr){
            next = curr -> next;
            curr -> next = prev;
            if(next){
                if(next->next == nullptr) prev->next = next;
                else{
                    prev->next = next->next;
                }
            }else{
                prev -> next = nullptr;
            }
            prev = next;
            curr = next ? next->next : nullptr;
        }

        return headDummy ? headDummy : head;
    }
};