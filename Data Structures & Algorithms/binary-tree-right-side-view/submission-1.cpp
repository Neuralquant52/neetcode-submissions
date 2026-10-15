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
    vector<int> rightSideView(TreeNode* root) {
        std::queue<TreeNode*> queue;
        if (root) queue.push(root);
        std::vector<int> res;

        int level{};
        while (!queue.empty()){
            int length = queue.size();

            for (int i{}; i < length; i++){
                TreeNode* curr = queue.front(); queue.pop();
                if (i == 0) res.push_back(curr->val);
                if (curr->right) queue.push(curr->right);
                if (curr->left) queue.push(curr->left);
            }
            level++;
        }
        return res;
    }
};
