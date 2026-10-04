class Solution {
public:
    bool isValid(string s) {
        std::stack<char> data_;
//        if (!(s.size() % 2)) return false;

        for (auto i : s){
            if ((i == '}' || i == ']' || i == ')') && data_.empty()) return false;
            if (i == ']' && data_.top() == '[') data_.pop();
            else if (i == '}' && data_.top() == '{') data_.pop();
            else if (i == ')' && data_.top() == '(') data_.pop();
            else data_.push(i);

        }
        return data_.empty();
    }
};
