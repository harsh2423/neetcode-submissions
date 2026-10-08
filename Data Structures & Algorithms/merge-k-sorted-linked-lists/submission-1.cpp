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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (lists.empty()) return nullptr;
        struct compare{
            bool operator()(ListNode* a, ListNode* b)
            {
                return a->val>b->val;
            }
        };
        priority_queue<ListNode*,vector<ListNode*>,compare> heap;
        for(ListNode* list: lists){
            if(list) heap.push(list);
        }   
        ListNode* res= new ListNode(0);
        ListNode* curr= res;
        while(!heap.empty())
        {
            ListNode* node = heap.top();
            heap.pop();
            curr->next=node;
            curr=curr->next;

            node=node->next;
            if(node)
            {
                heap.push(node);
            }
        }
        return res->next;
    }
};
