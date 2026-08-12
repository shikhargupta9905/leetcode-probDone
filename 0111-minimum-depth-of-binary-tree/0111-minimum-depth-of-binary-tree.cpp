class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL ) return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        // If one of the children is NULL, take the depth of the non-NULL child
        if (l==0 || r==0) return 1+ max(l,r);
        return 1+min(l,r);
    }
};