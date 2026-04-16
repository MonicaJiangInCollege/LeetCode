/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        if (!root) return result;
        
        stack<Node*> stk;
        stk.push(root);
        
        // 迭代：按 根 -> 孩子从右到左 的顺序访问，最后反转结果
        while (!stk.empty()) {
            Node* curr = stk.top();
            stk.pop();
            result.push_back(curr->val);
            
            // 注意：这里按从左到右的顺序压入孩子
            // 这样栈顶是最后一个孩子，实现“根->最右孩子”的顺序
            for (Node* child : curr->children) {
                stk.push(child);
            }
        }
        // 反转得到后序遍历
        reverse(result.begin(), result.end());
        return result;
    }
};