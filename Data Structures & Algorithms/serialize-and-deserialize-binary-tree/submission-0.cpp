/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);

        string res;
        while (!q.empty()){
            int sz = q.size();
            for (int i{}; i < sz; i++){
                TreeNode* curr = q.front(); q.pop();
                if (!curr) {
                    res += "n,";
                    continue;
                }
                res += std::to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        std::cout << res << '\n';
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals;
        stringstream ss(data);
        string curr;

        while (std::getline(ss, curr, ',')){
            vals.push_back((curr));
        }

        queue<TreeNode*> q;

        TreeNode* root = (vals.empty() || vals[0] == "n") ? nullptr : new TreeNode(std::stoi(vals[0]));
        q.push(root);

        int idx{1};      
        while (!q.empty() && idx < vals.size()){
            TreeNode* curr = q.front(); q.pop();
            if (vals[idx] != "n"){
                curr->left = new TreeNode(std::stoi(vals[idx]));
                q.push(curr->left);
            }
            idx++;

            if (vals[idx] != "n"){
                curr->right = new TreeNode(std::stoi(vals[idx]));
                q.push(curr->right);
            }
            idx++;
        }
        return root;
    }
};
