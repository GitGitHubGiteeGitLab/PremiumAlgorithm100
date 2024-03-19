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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(-1);
        ListNode *prev = &dummy;
        prev->next = head;
        while(prev->next && prev->next->next){
            ListNode* first = prev->next;
            ListNode* second = first->next;
            ListNode* secondNext = second->next;
            prev->next = second;
            second->next = first;
            first->next = secondNext;
            prev = first;
        }
        return dummy.next;
    }
};