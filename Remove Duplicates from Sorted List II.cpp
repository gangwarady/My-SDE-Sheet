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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        while(head->val==head->next->val){
            while(head!=NULL && head->next!=NULL && head->val==head->next->val){
                head=head->next;
            }
            
            head= head->next;
            if(head==NULL || head->next==NULL){
                return head;
            }
            
        }
        
        
        ListNode* curr = head;
        ListNode* prev = new ListNode(-1, curr);
        //prev->next = curr;
        while(curr!=NULL && curr->next!=NULL){
            ListNode* nexy = curr->next;
            if(curr->val==nexy->val){
                while(curr!=NULL && curr->next!=NULL && curr->val==nexy->val){
                    curr= curr->next;
                    nexy= nexy->next; 
                }
                curr= curr->next;
                prev->next = curr;
            }
            else{
                curr = curr->next;
                prev = prev->next;
            }
        }
        return head;
    }
};
