class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int final_{};
        for (int L{}; (L + k) <= arr.size(); L++){
            int R{L+1};
            int total{arr[L]};
            while (R < (L+k) && R < arr.size()){
                total += arr[R];
                R++;
            }

            if ((total / k) >= threshold) final_++;
        }
        return final_;
    }
};