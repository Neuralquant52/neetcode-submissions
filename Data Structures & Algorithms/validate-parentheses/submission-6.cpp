class Solution {
public:
    bool isValid(string s) {

        std::stack<char> stack0;
        if (s[0] == ']' || s[0] == '}' || s[0] == ')') return false;
        for (int i{0}; i < s.size(); i++){
            if (s[i] == '[' || s[i] == '{' || s[i] == '(') stack0.push(s[i]);   
            else if (stack0.size() > 0 && s[i] == ']' && stack0.top() == '[') stack0.pop();
            else if (stack0.size() > 0 && s[i] == '}' && stack0.top() == '{') stack0.pop();
            else if (stack0.size() > 0 && s[i] == ')' && stack0.top() == '(') stack0.pop();
            else return false;
        }

        return (stack0.size() == 0);
    }
};
