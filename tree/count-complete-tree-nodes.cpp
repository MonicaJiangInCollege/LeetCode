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
    int countNodes(TreeNode* root) {
        if (!root) 
            return 0;
        int leftH = getHeight(root->left);
        int rightH = getHeight(root->right);
        if (leftH == rightH) {
            // 左子树是满二叉树，右子树继续递归
            return (1 << leftH) + countNodes(root->right);
        }
        else {
            // 右子树是满二叉树，左子树继续递归
            return (1 << rightH) + countNodes(root->left);
        }
    }
private:
    int getHeight(TreeNode* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->left;
        }
        return h;
    }
};