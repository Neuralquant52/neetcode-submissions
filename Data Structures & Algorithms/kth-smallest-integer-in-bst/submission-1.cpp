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
    TreeNode* traversal(TreeNode* root, std::vector<int>& vec){
        if (!root) return nullptr;
        
        traversal(root->left, vec);
        vec.push_back(root->val);
        traversal(root->right, vec);
        return root;
    }

    int kthSmallest(TreeNode* root, int k) {
        std::vector<int> vec;
        TreeNode* x = traversal(root, vec);
        return vec[k-1];  
    }
};
