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
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (!root) return result;
        
        // Iterative approach using stack
        stack<Node*> stk;
        stk.push(root);
        
        while (!stk.empty()) {
            Node* curr = stk.top();
            stk.pop();
            result.push_back(curr->val);
            
        // Push children in reverse order so that leftmost is processed first
            for (int i = curr->children.size() - 1; i >= 0; --i) {
                if (curr->children[i]) {
                    stk.push(curr->children[i]);
                }
            }
        }
        
        return result;
    }
};