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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> queue_;
        if (root) queue_.push(root);

        vector<vector<int>> res;
        int level{};

        while (!queue_.empty()){
            int length = queue_.size();
            vector<int> vec;
            
            for (int i{}; i < length; i++){
                TreeNode* curr = queue_.front();
                queue_.pop();
                vec.push_back(curr->val);
                if (curr->left) queue_.push(curr->left);
                if (curr->right) queue_.push(curr->right);
            }
            res.push_back(vec);
            level++;
        }
        return res;
    }
};
