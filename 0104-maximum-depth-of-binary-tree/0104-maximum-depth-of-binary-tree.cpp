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
    int depth(TreeNode*a,int cnt){
        if(!a){
            return cnt;
        }
       return max(depth(a->left,cnt+1),depth(a->right,cnt+1));
        
    }
    int maxDepth(TreeNode* root) {
        return depth(root,0); 
    }
};