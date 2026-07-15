class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int x = 0;
        int y = numbers.size() - 1;

        while (x < y){
            if (x == y){x++; y--;}
            if (numbers[x] + numbers[y] < target) x++;
            else if (numbers[x] + numbers[y] > target) y--;
            else return std::vector<int> {x+1, y+1};
        }
        
        return numbers;
    }
};
