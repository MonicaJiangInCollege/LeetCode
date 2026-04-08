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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        depth(root, diameter);
        return diameter;
    }
    
private:
    int depth(TreeNode* node, int& diameter) {
        if (!node) return 0;
        int leftDepth = depth(node->left, diameter);
        int rightDepth = depth(node->right, diameter);
        // 更新经过当前节点的最长路径
        diameter = max(diameter, leftDepth + rightDepth);
        // 返回当前节点的深度
        return 1 + max(leftDepth, rightDepth);
    }
};