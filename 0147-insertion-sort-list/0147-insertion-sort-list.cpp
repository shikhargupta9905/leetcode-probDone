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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr && head->next==nullptr) return head;

        ListNode* dummy = new ListNode(0);
        ListNode* curr = head;

        while(curr!= nullptr){
            //save next node
             ListNode* nextNode = curr->next;

             //find correct position in sorted list
              ListNode* prev = dummy;

              while(prev->next != nullptr && prev->next->val < curr->val){
                prev =prev->next;
              }
                //insert current node
                curr->next = prev->next;
                prev->next= curr;

                //move to next 
                curr = nextNode;
              }
        return dummy->next;
    }
};