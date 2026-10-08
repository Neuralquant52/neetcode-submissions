class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        size_t m{};
        size_t N{matrix.front().size()};

        size_t L{};
        size_t R{N};

        while (m < matrix.size()){
            if (L >= R) {
                m++, L = 0, R = N;
                continue;
            }

            int mid = L + (R - L) / 2;

            if (matrix[m][mid] < target) L = mid + 1;
            else if (matrix[m][mid] > target) R = mid;
            else return true;
        }
        return false;
    }
};
