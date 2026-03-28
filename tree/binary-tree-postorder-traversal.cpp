class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }

    void dfs(TreeNode* node, vector<int>& res) {
        if (node == nullptr) 
            return;
        dfs(node->left, res); // 遍历左子树
        dfs(node->right, res); // 遍历右子树
        res.push_back(node->val); // 访问根节点
    }

};