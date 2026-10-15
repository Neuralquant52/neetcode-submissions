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
    int DFS(TreeNode* root, int& maxSum){
        if (!root) return 0;

        int leftMax = std::max(DFS(root->left, maxSum), 0);
        int rightMax = std::max(DFS(root->right, maxSum), 0);

        int pathSum = root->val + leftMax + rightMax;
        maxSum = std::max(maxSum, pathSum);

        return root->val + std::max(leftMax, rightMax);
    }

    int maxPathSum(TreeNode* root) {
        int sum{root->val};
        DFS(root, sum);
        return sum;
    }
};
