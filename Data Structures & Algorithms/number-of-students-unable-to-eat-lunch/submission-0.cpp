class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        for (int i{0}; i < 1000; i++){
            if (students.empty() && sandwiches.empty()){
                return 0;
            }
            if (students[0] == sandwiches[0]){
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
            } else {
                students.push_back(students[0]);
                students.erase(students.begin());
            }
            i++;
        }

        return students.size();
    }
};