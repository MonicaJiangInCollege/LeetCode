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
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true;
        else if (left == NULL || right == NULL) return false;
        else {
            if (left->val != right->val) return false;
            if (isMirror(left->left,right->right)==false) return false;
            if (isMirror(left->right,right->left)==false) return false;
            return true;
        }
    }
};