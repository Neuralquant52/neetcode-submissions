class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int current_row = 0;
        int low = 0;
        int high = matrix[current_row].size() - 1;

        while (low <= high && current_row < matrix.size()){
            int mid = (low + high) / 2;
            if (matrix[current_row][mid] < target){
                if (mid == matrix[current_row].size() - 1){
                    high = matrix[current_row].size() - 1;
                    low = 0;
                    current_row++;
                } 
                else low = mid + 1;
            } 
            else if (matrix[current_row][mid] > target) high = mid - 1;
            else return true;
        }
        return false;
    }
};
