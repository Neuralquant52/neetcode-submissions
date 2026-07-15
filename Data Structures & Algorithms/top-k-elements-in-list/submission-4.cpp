#include <map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> final;
        map<int, int> freq;
        for (int x : nums) freq[x]++;
        vector<pair<int,int>> vec(freq.begin(), freq.end());

        std::sort(vec.begin(), vec.end(), [](pair<int,int>& a, pair<int,int>& b) {
            return a.second > b.second;
        });

        for (int i{0}; i < k; i++) final.push_back(vec[i].first);
        return final;
    }
};
 