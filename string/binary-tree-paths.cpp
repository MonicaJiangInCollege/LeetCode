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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;          // 存放所有路径
        if (!root) return result;       // 空树直接返回空结果
        dfs(root, to_string(root->val), result); // 从根开始，路径初始值为根节点的值
        return result;
    }

private:
    void dfs(TreeNode* node, string path, vector<string>& result) {
        // 如果是叶子节点，当前路径就是一条完整的路径，加入结果
        if (!node->left && !node->right) {
            result.push_back(path);
            return;
        }
        // 如果有左子树，递归左子树，路径加上 "->左子节点值"
        if (node->left) {
            dfs(node->left, path + "->" + to_string(node->left->val), result);
        }
        // 如果有右子树，递归右子树
        if (node->right) {
            dfs(node->right, path + "->" + to_string(node->right->val), result);
        }
    }
};