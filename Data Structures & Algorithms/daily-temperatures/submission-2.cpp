class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result;
        bool found = false;
        for (int x{0}; x < temperatures.size(); x++){
            for (int y{x+1}; y < temperatures.size(); y++){
                if (temperatures[y] > temperatures[x]) {
                    result.push_back(y-x);
                    found = true;
                    break;
                } 
            }
            if (found == false) result.push_back(0);
            else found = false;
        }

        return result;
    }
};
