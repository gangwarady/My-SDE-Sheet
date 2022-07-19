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
        if(head==NULL){
            return NULL;
        }
        ListNode* curr= head;
        if(curr->next!=NULL){
            head = curr->next;
        }
        while(curr!=NULL && curr->next!=NULL){
            ListNode* nex = curr->next;
            curr->next = nex->next;
            nex->next = curr;
            curr = curr->next;
            if(curr!=NULL && curr->next!=NULL)
                nex->next->next = curr->next;
        }
        return head;
    }
};
