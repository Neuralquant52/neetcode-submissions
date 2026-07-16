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
        vector<vector<int>> final;
        std::deque<TreeNode*> q;  
        q.push_back(root);

        while (!q.empty()){
            int qLen = q.size();
            vector<int> level;
            for (int i{0}; i < qLen; i++){
                TreeNode* node = q.front();
                q.pop_front();

                if (node != nullptr){
                    level.push_back(node->val);
                    q.push_back(node->left);
                    q.push_back(node->right);
                }
            }
            if (!level.empty()) final.push_back(level);
        }
        return final;
    }
};
