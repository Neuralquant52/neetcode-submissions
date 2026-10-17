struct TrieNode{
    bool word = false;
    std::map<char, TrieNode*> children;
};

class Trie{
public:
    void insert(string word){
        TrieNode* curr = &root;
        for (char c : word){
            if (curr->children.find(c) == curr->children.end()) curr->children[c] = new TrieNode;
            curr = curr->children[c];
        }
        curr->word = true;
    }

    bool search(string word){
        TrieNode* curr = &root;
        for (char c : word){
            if (curr->children.find(c) == curr->children.end()) return false;
            curr = curr->children[c];
        }
        return curr->word;
    }

    bool startsWith(string word){
        TrieNode* curr = &root;
        for (char c : word){
            if (curr->children.find(c) == curr->children.end()) return false;
            curr = curr->children[c];
        }
        return true;
    }

    TrieNode root;
};

class Solution {
public:
    void helper(vector<vector<char>>& grid, int r, int c, set<pair<int, int>>& visits, TrieNode* curr, string word, set<string>& res){
        if (curr->word) res.insert(word);        
        int rows = grid.size(); int columns = grid.front().size();

        if (std::min(r, c) < 0 || r == rows || c == columns ||
        visits.contains({r, c})) return;

        if (curr->children.find(grid[r][c]) != curr->children.end()) {
            curr = curr->children[grid[r][c]];
            word += grid[r][c];
        }
        else return;
 
        visits.insert({r, c});
        helper(grid, r+1, c, visits, curr, word, res);
        helper(grid, r-1, c, visits, curr, word, res);
        helper(grid, r, c+1, visits, curr, word, res);
        helper(grid, r, c-1, visits, curr, word, res);

        visits.erase({r, c});
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<string> res;
        std::set<pair<int, int>> visits;
        string curr = "";
        for (string word : words) trie_.insert(word);

            
        for (int x{}; x < board.size(); x++){
            for (int y{}; y < board.front().size(); y++){
                TrieNode* root = &trie_.root;
                helper(board, x, y, visits, root, curr, res);
                curr.clear();
                visits.clear();
            }
        }
    
        return vector<string>(res.begin(), res.end());
    }

private:
    Trie trie_;
};
