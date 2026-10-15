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
    TreeNode* minNode(TreeNode* root){
        TreeNode* curr = root;
        while (curr->left != nullptr) {curr = curr->left;}
        return curr;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        
        if (key > root->val) root->right = deleteNode(root->right, key);
        else if (key < root->val) root->left = deleteNode(root->left, key);
        else {
            if (!root->right) return root->left;
            if (!root->left) return root->right;
            
            TreeNode* min = minNode(root->right);
            root->val = min->val;
            root->right = deleteNode(root->right, min->val);
        }
        return root;
    }
};