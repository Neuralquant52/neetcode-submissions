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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr){
            root = new TreeNode;
            root->val = val;
            return root;
        }
        TreeNode* curr = root;
        TreeNode* new_node = new TreeNode;
        new_node->val = val;
        while (true) {
            if (new_node->val > curr->val){
                if (curr->right == nullptr){
                    curr->right = new_node;
                    break;
                }
                else curr = curr->right;
            } else if (new_node->val < curr->val){
                if (curr->left == nullptr){
                    curr->left = new_node;
                    break;
                }
                else curr = curr->left;
            }
        }
        return root;
    }
};