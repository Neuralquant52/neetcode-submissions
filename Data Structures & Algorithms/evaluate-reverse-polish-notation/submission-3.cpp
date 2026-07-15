class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack0;
        for (int i{0}; i < tokens.size(); i++){
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                stack0.push(std::stoi(tokens[i]));
            } else if (stack0.size() >= 2){
                int num1 = stack0.top();
                stack0.pop();
                int num2 = stack0.top();
                stack0.pop();
                if (tokens[i] == "-") stack0.push(num2 - num1);
                else if (tokens[i] == "+") stack0.push(num1 + num2);
                else if (tokens[i] == "*") stack0.push(num1 * num2);
                else if (tokens[i] == "/") stack0.push(num2 / num1);
            }
        }
        return stack0.top();
    }
};
