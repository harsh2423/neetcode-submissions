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
    bool hasCycle(ListNode* head) 
    {
        if(head==NULL) return false;
        
        ListNode* slo=head;
        ListNode* fas=head;
        while(fas!=NULL && fas->next!=NULL)
        {
            if(fas->next->next)
            {
                fas=fas->next->next;
                slo=slo->next;
                if(fas->val==slo->val)
                {
                   return true;
                }
            }
            else fas=fas->next;
            
        }
        return false;
    }
};
