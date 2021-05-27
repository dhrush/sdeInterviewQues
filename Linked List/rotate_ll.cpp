class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL || k==0 || head->next == NULL)  return head;
        
        ListNode* p = head;
        int length = 0;
        while(p!=NULL)
        {
            p = p->next;
            length++;
        }
        
        int maxRotations = k % length;
        
        for(int i=0; i<maxRotations; i++)
        {
            ListNode* s = head;
            ListNode* q = NULL;
            while(s->next!=NULL)
            {
                q = s;
                s = s->next;
            }
            q->next = NULL;
            s->next = head;
            head = s;            
        }
        return head;
    }
};