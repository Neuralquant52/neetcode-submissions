struct TrieNode{
    std::unordered_map<char, TrieNode*> children;
    bool word = false;
};

class WordDictionary {
public:
    void addWord(string word) {
        TrieNode* curr = &root;
        for (auto c : word){
            if (curr->children.find(c) == curr->children.end()) curr->children[c] = new TrieNode;
            curr = curr->children[c];
        }
        curr->word = true;
    }
    
    bool search(string word) {

        TrieNode* curr = &root;
        return searchHelper(word, 0, curr);
    }
private:
    TrieNode root;

    bool searchHelper(string word, int idx, TrieNode* node){
        if (idx == word.length()) return node->word;
        char c = word[idx];
        if (c == '.'){
            for (auto& [ch, next] : node->children){
                if (searchHelper(word, idx + 1, next)) return true;
            }
            return false;
        }

        if (node->children.find(c) == node->children.end()) return false;

        return searchHelper(word, idx + 1, node->children[c]);
    }

};
