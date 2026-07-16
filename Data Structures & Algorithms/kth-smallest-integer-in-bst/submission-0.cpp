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
    void sort_tree(TreeNode* root, vector<int>& vec){
        if (root == nullptr) return;

        sort_tree(root->left, vec);
        vec.push_back(root->val);
        sort_tree(root->right, vec);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        sort_tree(root, vec);
        return vec[k - 1];
    }
};
