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
    int minDepth(TreeNode* root) {
        if (!root) 
            return 0;                     // 空树深度为 0

        if (!root->left) 
            return 1 + minDepth(root->right); // 只有右子树

        if (!root->right) 
            return 1 + minDepth(root->left);  // 只有左子树

        return 1 + min(minDepth(root->left), minDepth(root->right)); // 左右子树均存在
    }
};