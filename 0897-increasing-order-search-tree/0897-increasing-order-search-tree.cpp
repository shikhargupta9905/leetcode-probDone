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

void inorder(TreeNode*& curr, TreeNode*root){
       if(root==nullptr) return ;
        inorder( curr,root->left);
        curr->right= root;
        root->left= nullptr;
        curr=root;
        inorder(curr ,root->right);
}
    TreeNode* increasingBST(TreeNode* root) {
     TreeNode* dummy= new TreeNode(0);
     TreeNode* curr=dummy;
     
     inorder(curr,root);
     return dummy->right;
    }
};