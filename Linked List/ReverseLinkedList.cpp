class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        
        if(head == NULL)
            return NULL;
        else
        {
            ListNode* s = head;
            ListNode *p = NULL;
            ListNode *q = NULL;
            while(s != NULL)
            {
                q = s;
                s = s->next;
                q->next = p;
                p = q;
            }
            s = q;
            return s;            
        }
    }
};