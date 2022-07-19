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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* ans = new ListNode(0);
        ListNode* prev = ans;
        while(temp1!=NULL || temp2!=NULL){
            ListNode* newnode = new ListNode(0);
            if(temp1==NULL){
                newnode->val = temp2->val + carry;
                carry = (newnode->val)/10;
                newnode->val = newnode->val%10;
                temp2 = temp2->next;
                prev->next = newnode;
                prev = newnode;
            }
            else if(temp2==NULL){
                newnode->val = temp1->val + carry;
                carry = (newnode->val)/10;
                newnode->val = newnode->val%10;
                temp1 = temp1->next;
                prev->next = newnode;
                prev = newnode;
            }
            else{
                newnode->val = temp1->val + temp2->val + carry;
                carry = (newnode->val)/10;
                newnode->val = newnode->val%10;
                temp1 = temp1->next;
                temp2 = temp2->next;
                prev->next = newnode;
                prev = newnode;
            }
        }
        if(carry){
            ListNode* newnode = new ListNode(carry);
            prev->next = newnode;
        }
        return ans->next;
    }
};
