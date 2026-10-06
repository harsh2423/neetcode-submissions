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
    void reorderList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL) return;
        ListNode* slo=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next)
        {
            slo=slo->next;
            fast=fast->next->next;
        }
        ListNode* second=slo->next;
        slo->next=NULL;

        ListNode* prev = NULL;
        ListNode* curr = second;
        while(curr)
        {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        ListNode* first = head;

        while(prev)
        {
            ListNode* firstnext=first->next;
            ListNode* secnext=prev->next;
            
            first->next=prev;
            prev->next=firstnext;

            first=firstnext;
            prev=secnext;
        }
    }
};
