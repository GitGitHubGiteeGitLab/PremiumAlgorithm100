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

struct Compare{
    bool operator()(const ListNode* first , const ListNode* second){
        //向下调整的条件
        return first->val > second->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        //如何定义比较方法
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        ListNode dummy(-1);
        ListNode *tail = &dummy;
        //如何遍历元素
        for(size_t i = 0; i < k; ++i){
            if(lists[i])
                pq.push(lists[i]);
        }

        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            tail->next = node;
            tail = node;
            if(node->next)
                pq.push(node->next);
        } 
        return dummy.next;
    }
};

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //merge如何带回合并结果
        //通过返回值
        return _mergeKLists(lists, 0, lists.size() - 1);   
    }

    ListNode* _mergeKLists(vector<ListNode*>& lists, int l, int r){
        if(l > r)return nullptr;
        if(l == r)return lists[l];


        int m = (l + r) >> 1;
        ListNode *l1 = _mergeKLists(lists, l, m);
        ListNode *l2 = _mergeKLists(lists, m + 1, r);

        return merge(l1, l2); 
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        if(l1 == nullptr)return l2;
        if(l2 == nullptr)return l1;

        ListNode dummy(-1);
        ListNode *tail = &dummy;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }else{
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }

        if(l1)tail->next = l1;
        if(l2)tail->next = l2; 
        return dummy.next;
    }
};