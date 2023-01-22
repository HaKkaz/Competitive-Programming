/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0 , MX = 0;
    void dfs(TreeNode *now , int deep){
        if(!now->left and !now->right){
            if(deep > MX){
                MX = deep;
                ans = now->val;
            }
            else if(deep == MX){
                ans += now->val;
            }
        }
        if(now->left != nullptr) dfs(now->left , deep+1);
        if(now->right!= nullptr) dfs(now->right , deep+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        if(root == nullptr) return 0;
        dfs(root,0);
        return ans;
    }
};