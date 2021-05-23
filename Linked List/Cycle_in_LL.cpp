class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        if(head == NULL || head->next == NULL)  return false;
        ListNode* p = head;
        ListNode* q = head;
        
        
        while(q->next!=NULL && q->next->next!=NULL)
        {
            p = p->next;
            q = q->next->next;
            if(p==q)
            {
                return true;
            }
        }
        
        return false;
        
    }
};