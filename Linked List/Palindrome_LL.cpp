class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        //Brute Force: Copy LL into vector then normal check for palindrome
        
        //traverse till middle of LL after that reverse the LL ahead then compare both head and mid
        if(head == NULL || head->next == NULL)  return true;
        
        ListNode* slow = head;
        ListNode* fast = head;        
        
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* dummy = slow;
        slow = slow->next;
        
        ListNode* s = slow;
        ListNode* p = NULL;
        ListNode* q = NULL;
        while(s!=NULL)
        {
            p=q;
            q=s;
            s=s->next;
            q->next=p;
        }
        dummy->next = q;
        dummy=dummy->next;
        
        while(dummy!=NULL)
        {
            if(head->val == dummy->val)
            {
                head=head->next;
                dummy=dummy->next;
            }
            else
            {
                return false;
            }
        }
        return true;
        
    }
};