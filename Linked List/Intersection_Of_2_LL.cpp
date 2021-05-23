//Better Appraoch
//Best Appraoch

//Better approach
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
     {
        //this is O(m+n)
        int m = 0;
        int n = 0;
        
        ListNode* s1 = headA;
        ListNode* s2 = headB;
        
        while(s1!=NULL)
        {
            s1=s1->next;
            m++;
        }
        
        while(s2!=NULL)
        {
            s2=s2->next;
            n++;
        }
        
        ListNode* d1 = headA;
        ListNode* d2 = headB;
        int diff = m-n;
        if(diff<0)  diff*=-1;
        if(m>n) for(int i=0; i<diff; i++)   d1=d1->next;
        else if(m<n)    for(int i=0; i<diff; i++)   d2=d2->next;
        
        while(d1!=d2 && d1!=NULL && d2!=NULL)
        {
            d1 = d1->next;
            d2 = d2->next;
        }
        if(d1 == d2)    return d1;
        else    return NULL;
        
     }
};



//Best approach
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA == NULL || headB == NULL)  return NULL;
        ListNode* d1 = headA;
        ListNode* d2 = headB;
        while(d1!=d2)
        {
            d1 = d1==NULL?headB:d1=d1->next;
            d2 = d2==NULL?headA:d2=d2->next;
        }
        return d1;
    }
};