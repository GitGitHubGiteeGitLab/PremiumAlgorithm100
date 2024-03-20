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
    void reorderList(ListNode* head) {
        if(!head || !head->next)return;
        //1.中间节点
        ListNode *midLeft = getMidNode(head);
        ListNode *midRight = midLeft->next;
        midLeft->next = nullptr;

        //2.逆置后半部分
        midRight = reverseList(midRight);

        //3.合并两个链表
        head = MergeLists(head, midRight);

    }
    ListNode* getMidNode(ListNode* head){
        ListNode dummy(-1); 
        dummy.next = head;
        ListNode* fast = &dummy, *slow = &dummy;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next; 
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next)return head;
        ListNode *prev = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;
        while(cur){
            next = cur->next;
            cur->next = prev;
            prev = cur; 
            cur = next;
        }
        return prev;
    }
    
    ListNode* MergeLists(ListNode* head1, ListNode* head2){
        if(!head1)return head2;
        if(!head2)return head1;
        ListNode *cur1 = head1;
        ListNode *cur2 = head2;
        while(cur2){
            ListNode *tmp1 = cur1->next;
            ListNode *tmp2 = cur2->next;
            cur1->next = cur2; 
            cur2->next = tmp1; 
            cur1 = tmp1;
            cur2 = tmp2;
        }
        return head1; 
    }
};
