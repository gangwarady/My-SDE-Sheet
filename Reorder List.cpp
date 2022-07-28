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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newNode = slow->next;
        slow->next = NULL;
        ListNode *curr = newNode;
        ListNode *prev = NULL;
        
        while(curr != NULL) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        newNode = prev;
        ListNode *h1, *h2;
        h1 = head;
        h2 = newNode;
        
        while(h2) {
            ListNode *next = h1->next;
            h1->next = h2;
            h1 = h2;
            h2 = next;
        }
    }
};
