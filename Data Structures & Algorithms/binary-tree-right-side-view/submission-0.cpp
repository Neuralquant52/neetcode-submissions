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
        std::deque<TreeNode*> q;
        q.push_back(root);
        vector<int> vec;

        while(!q.empty()){
            int qLen = q.size();
            

            for (int i{0}; i < qLen; i++){
                TreeNode* node = q.front();
                q.pop_front();

                if (node != nullptr){
                    if (i == 0)  vec.push_back(node->val);

                    if(node->right) q.push_back(node->right);
                    if(node->left) q.push_back(node->left);
                }

            }
        }
        return vec;
    }
};
