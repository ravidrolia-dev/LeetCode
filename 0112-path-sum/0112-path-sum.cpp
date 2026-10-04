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
    bool hasPathSum(TreeNode* root, int targetsum) {
        int sum = 0;
        return inorder(root,sum,targetsum);
    }
    bool inorder(TreeNode* root , int &sum ,int targetsum){
        if(root == nullptr){
            return false;
        }
        sum += root->val;
        if(root->left == nullptr && root->right == nullptr){
            bool ans = (sum == targetsum);
            sum -= root->val;
            return ans;
        }
        bool ans =  inorder(root->left,sum,targetsum) || inorder(root->right,sum,targetsum);
        sum -= root->val;
        return ans;
    }
};