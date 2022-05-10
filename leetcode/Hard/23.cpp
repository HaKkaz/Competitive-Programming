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
        const int n = lists.size();
        if(n == 0){
            return nullptr;
        }
        ListNode *cur[n] , *now = nullptr ,*head = nullptr;
        priority_queue< pair<int,int> > pq;
        for(int i=0 ; i<n ; ++i){
            if(lists[i] != nullptr){
                cur[i] = lists[i];
                pq.emplace(-cur[i]->val , i);
            }
        }
        bool first=1;
        while(pq.size()){
            auto [value , id] = pq.top();
            pq.pop();
            if(first){
                first = 0;
                now = new ListNode(-value);
                head = now;
            }else{
                now->next = new ListNode(-value);
                now = now->next;
            }
            
            if(cur[id]->next != nullptr){
                cur[id] = cur[id]->next;
                pq.emplace(-cur[id]->val , id);
            }
        }
        return head;
    }
};