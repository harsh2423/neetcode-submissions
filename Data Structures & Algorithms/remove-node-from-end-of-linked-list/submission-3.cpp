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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int total=0;
        ListNode* temp=head;
        
        while(temp)
        {
            total++;
            temp=temp->next;
        }
        int final=total-n+1;
        int i=1;
        if(final==1)
        {
            return head->next;
        }
        temp=head;
        ListNode* prev=temp;
        while(i<final)
        {
            prev=temp;
            temp=temp->next;
            i++;
        }
        prev->next=temp->next;
        temp->next=NULL;
            
            return head;
    }
};
