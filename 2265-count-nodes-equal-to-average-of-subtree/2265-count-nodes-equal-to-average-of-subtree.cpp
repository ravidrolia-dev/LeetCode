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
    
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        res = inorder(root,res);
        return res;
    }
    int sum(TreeNode* root){
        if(!root)return 0;
        int total = 0 ;
        total += root->val;
        total += sum(root->left);
        total += sum(root->right);
        return total;
    }
    int inorder(TreeNode* root,int &res){
        if(!root)return 0;
        inorder(root->left,res);
        if(average(root) == root->val)res++;
        inorder(root->right,res);
        return res;
    }
    int count(TreeNode* root){
        if(!root)return 0;
        return count(root->left) + 1 + count(root->right);
    }
    int average(TreeNode* root){
        int total = sum(root);
        int cnt  = count(root);
        return total/cnt;

    }
};