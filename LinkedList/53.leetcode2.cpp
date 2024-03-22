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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        ListNode dummy(-1);
        ListNode* tail = &dummy;
        int dsum = 0;
        while(cur1 || cur2 || dsum){
            if(cur1){
                dsum += cur1->val; 
                cur1 = cur1->next;
            }
            if(cur2){
                dsum += cur2->val;
                cur2 = cur2->next;
            }
            ListNode *newnode = new ListNode(dsum % 10);
            tail->next =newnode;
            tail = newnode;
            dsum /= 10;
        }
        return dummy.next;
    }
};