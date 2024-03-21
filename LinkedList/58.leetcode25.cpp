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
    //第一个念头：先反转第一个k个，再翻转第二k个
    //没错，但是少了一步：先统计要一共有几个组要翻转
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next)return head;
        int n = 0;
        ListNode* cur = head;
        while(cur){
            n++;
            cur = cur->next;
        }

        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = &dummy;
        cur = prev->next;
        for(int i = 0, I = n / k; i < I; i++){
            ListNode *tmp = cur;
            for(int j = 0; j < k; j++){
                ListNode* next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
                cur = next;
            }
            prev = tmp;
        }
        //易忘
        prev->next = cur;
        return dummy.next;
    }
};