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
    void traverse(TreeNode* root, int &counter, int max_value = 0){
        if (root == nullptr) return;
        
        if (root != nullptr && root->val >= max_value) {
            max_value = root->val;
            counter++;
            }

        traverse(root->right, counter, max_value);
        traverse(root->left, counter, max_value);
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        traverse(root, count, root->val);
        return count;
    }
};
