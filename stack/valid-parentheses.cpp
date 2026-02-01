class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0)
            return false;
        stack<char>target;  
        // no need to initialize,C++ standard library automatically creates an empty stack
        
        for (char c : s) {
            if ((c == '(') || (c == '[') || (c == '{'))
                target.push(c);
            else if (target.empty())
                return false;
            else if ((c == ')') && (target.top() == '('))
                target.pop();
            else if ((c == ']') && (target.top() == '['))
                target.pop();
            else if ((c == '}') && (target.top() == '{'))
                target.pop();
            else
                return false;
        }

        if (target.empty())
            return true;
        else
            return false;
    }
};