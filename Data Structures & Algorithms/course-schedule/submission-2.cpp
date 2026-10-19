class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& graph, int node, vector<int>& state){
        if (state[node] == 1) return false;
        if (state[node] == 2) return true;

        state[node] = 1;
        for (auto neighbor : graph[node]){
            if (!dfs(graph, neighbor, state)) return false;;
        }
        state[node] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> state(numCourses, 0);
        for (auto edge : prerequisites){
            graph[edge[0]].push_back(edge[1]);
        }

        for (int i{}; i < numCourses; i++){
            if (state[i] == 0 && !dfs(graph, i, state)) return false;
        }
        return true;
    }
};
