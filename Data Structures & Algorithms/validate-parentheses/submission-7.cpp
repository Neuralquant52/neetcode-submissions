class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        for (int i : s){
            if (stck.empty()){
                if (i == ']' || i == ')' || i == '}') return false;
            }
            if (i == ')' && stck.top() == '(') stck.pop();
            else if (i == ']' && stck.top() == '[') stck.pop();
            else if (i == '}' && stck.top() == '{') stck.pop();
            else stck.push(i);
        }
        return stck.empty();
    }
};
