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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry = 0;
        ListNode* s = l1;
        ListNode* t = l2;
        ListNode* pq = NULL;
        while(l1 != NULL && l2 != NULL)
        {   
            pq = l1;
            int sum = carry + l1->val + l2->val;
            if(carry)   carry = 0;
            if(sum>9)
            {
                sum = sum%10;
                carry = 1;
            }
            l1->val = sum;
            l2->val = sum;
            l1=l1->next;
            l2=l2->next;
        }
        
        ListNode* dummy = NULL;
        
        if(l1==NULL)
        {
            if(l2!=NULL)
            {
                dummy = l2;     
                s = t;
            }
        }
        else if(l2 == NULL)
        {
            if(l1 != NULL)  dummy = l1;
        }
        
        ListNode* d2 = NULL;
        
        if(dummy)
        {
            while(dummy!=NULL)
            {
                d2 = dummy;
                int sum = carry + dummy->val;
                if(carry)   carry = 0;
                if(sum>9)
                {
                    sum = sum%10;
                    carry = 1;
                }
                dummy->val = sum;
                dummy = dummy->next;
            }            
        }
        if(carry)
        {
            ListNode* temp = new ListNode();
            temp->val = carry;
            if(d2)
            {
                d2->next = temp;    
            }
            else
            {
                pq->next = temp;
            }
            
        }
        return s;
        
    }
};