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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *cur = head;
        ListNode *ans = nullptr;
        ListNode *top = nullptr;
        while(cur){
            vector<int> tmp;
            while(cur && tmp.size()<k){
                tmp.emplace_back(cur->val);
                cur = cur->next;
            }
            if(tmp.size() == k){
                for(int i=k-1 ; i>=0 ; --i){
                    if(!ans){
                        ans = new ListNode(tmp[i]) , top = ans;
                    }
                    else{
                        top->next = new ListNode(tmp[i]);
                        top = top->next;
                    }
                }
            }
            else{
                for(int i=0 ; i<(int)tmp.size() ; ++i){
                    if(!ans){
                        ans = new ListNode(tmp[i]) , top = ans;
                    }
                    else{
                        top->next = new ListNode(tmp[i]);
                        top = top->next;
                    }
                }
            }
        }
        return ans;
    }
};