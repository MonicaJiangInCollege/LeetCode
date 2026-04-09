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
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        TreeNode* prev = nullptr;   // 前一个节点
        int curCount = 0;           // 当前值的出现次数
        int maxCount = 0;           // 全局最大出现次数

        inorder(root, prev, curCount, maxCount, result);
        return result;
    }

private:
    void inorder(TreeNode* node, TreeNode*& prev, int& curCount, int& maxCount, vector<int>& result) {
        if (!node) return;

        // 左子树
        inorder(node->left, prev, curCount, maxCount, result);

        // 处理当前节点
        if (prev == nullptr) {
            curCount = 1;                     // 第一个节点
        } else if (prev->val == node->val) {
            curCount++;                       // 相同值，累加
        } else {
            curCount = 1;                     // 新值，重新计数
        }

        // 更新结果集
        if (curCount > maxCount) {
            maxCount = curCount;
            result.clear();
            result.push_back(node->val);
        } else if (curCount == maxCount) {
            result.push_back(node->val);
        }

        // 更新 prev 并遍历右子树
        prev = node;
        inorder(node->right, prev, curCount, maxCount, result);
    }
};