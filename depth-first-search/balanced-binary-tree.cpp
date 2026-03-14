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
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
private:
    // 返回树的高度，如果不平衡则返回 -1
    int checkHeight(TreeNode* node) {
        if (node == nullptr) 
            return 0;

        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) 
            return -1; // 左子树不平衡

        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) 
            return -1; // 右子树不平衡

        // 检查当前节点是否平衡
        if (abs(leftHeight - rightHeight) > 1) 
            return -1;

        // 返回当前子树的高度
        return max(leftHeight, rightHeight) + 1;
    }
};