class Solution {
public:

    void helper(int i, vector<int>& comb, vector<vector<int>>& res, int n, int k){
        if (comb.size() == k){
            res.push_back(comb);
            return;
        }
        if (i > n) return;

        comb.push_back(i);
        helper(i + 1, comb, res, n, k);

        comb.pop_back();
        helper(i + 1, comb, res, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        helper(1, curr, res, n, k);
        return res;
    }
};