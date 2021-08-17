//https://leetcode.com/problems/path-sum/

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL){
            return false;
        }
        
        return traverse(root, 0, targetSum);
    }
    
    bool traverse(TreeNode* root, int sum, int targetSum){
        if (root == NULL){
            return false;
        }
        
        if (root->left == NULL && root->right == NULL){
            return (sum + root->val == targetSum);
        }
        
        if (traverse(root->left, sum + root->val, targetSum))
            return true;
        
        return traverse(root->right, sum + root->val, targetSum);
    }
};
