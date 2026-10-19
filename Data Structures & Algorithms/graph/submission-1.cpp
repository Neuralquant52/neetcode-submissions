class Graph {
public:
    Graph() {}

    void addEdge(int src, int dst) {
        data_[src].insert(dst);
    }

    bool removeEdge(int src, int dst) {
        if (data_.find(src) == data_.end() || !data_[src].contains(dst)) return false;
        data_[src].erase(dst);
        return true;
    }

    bool hasPath(int src, int dst) {
        set<int> visits;
        return dfs(src, dst, data_, visits);
    }

    int dfs(int node, int target, unordered_map<int, set<int>>& adjList, set<int>& visits){
        if (visits.contains(node)) return false;
        if (node == target) return true;

        visits.insert(node);

        auto it = adjList[node].begin();

        while (it != adjList[node].end()){
            if (dfs(*it, target, adjList, visits)) return true;
            it++;
        }
        return false;
    }
private:
    std::unordered_map<int, set<int>> data_;
};
