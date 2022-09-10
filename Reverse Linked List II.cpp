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
    ListNode* f(ListNode* head, int r){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nexty = NULL;
        while(r--){
            nexty = curr->next;
            curr->next = prev;
            prev = curr;
            curr=nexty;
        }
        head->next = curr;
        head = prev;
        return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
       
        ListNode* prev = dummy;
        for(int i =1; i<left; i++){
            prev = prev->next;
        }
         prev->next = f(prev->next, right-left+1);
        
        return dummy->next;
    }
};
