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
    int CountHeight(TreeNode* root){
        if (!root) return 0;

        return 1 + std::max(CountHeight(root->left), CountHeight(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int x = CountHeight(root->left);
        int y = CountHeight(root->right);

        return std::abs(x-y) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
