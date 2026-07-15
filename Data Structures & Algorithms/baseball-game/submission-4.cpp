class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> last_vec;
        int sum = 0;
        for (auto i{0}; i < operations.size(); ++i){
            string operation = operations[i];
            int vec_size = last_vec.size();
            if (operation == "C"){
                if (!last_vec.empty()) last_vec.pop_back();
            } else if (operation == "D"){
                last_vec.push_back(2 * last_vec.back());
            } else if (operation == "+"){
                if(last_vec.size() >= 2) last_vec.push_back(last_vec[vec_size-2] + last_vec[vec_size-1]);
            } else{
                last_vec.push_back(std::stoi(operation));
            }
        }
        for (auto i{0}; i < last_vec.size(); i++){
            sum += last_vec[i];
        }
        return sum;
    }
};