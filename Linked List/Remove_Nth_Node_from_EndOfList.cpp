//Optimal Solution O(n)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) 
    {
        if(head == NULL)    return head;
        else
        {
            ListNode* dummy = new ListNode();
            dummy->next = head;
            ListNode* f = dummy;
            ListNode* s = dummy;
            
            for(int i=0; i<k; i++)
            {
                f = f->next;                
            }
            
            while(f->next!=NULL)
            {
                s = s->next;
                f = f->next;
            }
            if(s == dummy)
            {
                head = head->next;
            }
            else
            {
                s->next = s->next->next;                
            }
            return head;
        }
        
    }
};

//O(2n) solution
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) 
    {
        if(head == NULL)    return head;
        else
        {
            ListNode* dummy = new ListNode();
            dummy->next = head;
            ListNode* f = dummy;
            ListNode* s = dummy;
            
            for(int i=0; i<k; i++)
            {
                f = f->next;                
            }
            
            while(f->next!=NULL)
            {
                s = s->next;
                f = f->next;
            }
            if(s == dummy)
            {
                head = head->next;
            }
            else
            {
                s->next = s->next->next;                
            }
            return head;
        }
        
    }
};