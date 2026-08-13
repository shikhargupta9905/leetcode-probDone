/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *fhead, ListNode *shead) {
        ListNode* temp1= fhead;
        ListNode* temp2 = shead;
         if(fhead==NULL || shead==NULL) return NULL;
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        
        if(temp1==temp2) return temp1;
        if(temp1==NULL) temp1= shead;
        if(temp2==NULL) temp2= fhead;
    }
    return temp1;
    }
};