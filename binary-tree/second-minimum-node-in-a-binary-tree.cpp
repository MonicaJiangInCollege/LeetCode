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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        return dfs(root, root->val);
    }
    
    int dfs(TreeNode* node, int minVal) {
        if (!node) return -1;
        // 如果当前节点值大于最小值，它就是一个候选
        if (node->val > minVal) return node->val;
        // 否则（等于最小值），继续在左右子树中寻找
        int left = dfs(node->left, minVal);
        int right = dfs(node->right, minVal);
        // 处理左右子树返回的结果，取较小的有效值
        if (left == -1) return right;
        if (right == -1) return left;
        return min(left, right);
    }
};