class Solution {
public:

    void dfs(unordered_map<int, vector<int>>& graph, int node, set<int>& visited){
        if (visited.contains(node)) return;

        visited.insert(node);
        for (auto neighbor : graph[node]){
            dfs(graph, neighbor, visited);
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        std::unordered_map<int, vector<int>> graph;
        for (auto neighbors : edges){
            graph[neighbors[0]].push_back(neighbors[1]);
            graph[neighbors[1]].push_back(neighbors[0]);
        }
        set<int> visited;

        dfs(graph, 0, visited);

        return visited.size() == n; 
    }
};
