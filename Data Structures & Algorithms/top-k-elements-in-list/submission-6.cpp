class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> final;
        vector<pair<int, int>> vec;
        pair<int, int> curr;
        for (int i : nums){
            if (i != curr.second){
                vec.push_back(curr);
                curr.first = 1;
                curr.second = i;
            } 
            else curr.first++;
        }
        vec.push_back(curr);
        sort(vec.begin(), vec.end(), greater<pair<int, int>>());
        for (int i{0}; i < k; i++) final.push_back(vec[i].second);
        return final;
    }
};
