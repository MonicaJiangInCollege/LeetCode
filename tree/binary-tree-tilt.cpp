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
    int findTilt(TreeNode* root) {
        int totalTilt = 0;
        postOrderSum(root, totalTilt);
        return totalTilt;
    }

private:
    // Returns the sum of the subtree rooted at 'node', and updates 'totalTilt' with the tilt of this node.
    int postOrderSum(TreeNode* node, int& totalTilt) {
        if (!node) return 0;

        int leftSum = postOrderSum(node->left, totalTilt);
        int rightSum = postOrderSum(node->right, totalTilt);

        int tilt = abs(leftSum - rightSum);
        totalTilt += tilt;

        return node->val + leftSum + rightSum;
    }
};