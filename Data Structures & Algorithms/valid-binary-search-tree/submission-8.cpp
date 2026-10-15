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
    bool Valid(TreeNode* root, int left, int right){
        if (!root) return true;
        if (!(root->val < right && root->val > left)) return false;
        return Valid(root->left, left, root->val) && Valid(root->right, root->val, right);
    }

    bool isValidBST(TreeNode* root) {
        
        return Valid(root, INT_MIN, INT_MAX);
    }
};
