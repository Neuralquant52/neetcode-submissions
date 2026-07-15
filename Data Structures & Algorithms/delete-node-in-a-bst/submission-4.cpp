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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        TreeNode* parent = root;
        TreeNode* curr = root;
        while (true){
            if (key < curr->val) {
                if (curr->left == nullptr) return root;
                else {
                    parent = curr;
                    curr = curr->left;
                    }
                }
            else if (key > curr->val) {
                if (curr->right == nullptr) return root;
                else {
                    parent = curr;
                    curr = curr->right;
                    }
                }
            else {
                if (curr->right != nullptr){
                    TreeNode* successor = curr->right;
                    while (successor->left != nullptr) {
                        successor = successor->left;
                    }
                    int successorVal = successor->val;
                    curr->right = deleteNode(curr->right, successorVal);
                    curr->val = successorVal;
                    break;
                } else if (curr->left != nullptr){
                    TreeNode* predecessor = curr->left;
                    while (predecessor->right != nullptr) {
                        predecessor = predecessor->right;
                    }
                    int predecessorVal = predecessor->val;
                    curr->left = deleteNode(curr->left, predecessorVal);
                    curr->val = predecessorVal;
                    break;
                } else {
                    if (curr == parent->left) parent->left = nullptr;
                    else if (curr == parent->right) parent->right = nullptr;
                    if (parent == curr) return nullptr;
                    break;
                }
                
            }
        }
        return root;
    }
};