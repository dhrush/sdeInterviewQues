class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {       
        ListNode* s = head;
        ListNode* p = s;
        ListNode* q = s;
        while(q != NULL && q->next != NULL && q->next->next != NULL)
        {
            p = p->next;
            q = q->next->next;
        }
        if(q->next!=NULL && q->next->next == NULL)
        {
            p = p->next;
        }
        return p;       
    }
};