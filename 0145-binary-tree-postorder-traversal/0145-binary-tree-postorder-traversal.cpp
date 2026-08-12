class Solution {
private:
    void solve(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return; // 'return;' is valid here because solve() is void

        solve(root->left, ans);
        solve(root->right, ans);
        ans.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};