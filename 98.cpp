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
    bool isValidBST(TreeNode* root) {
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        if (root->left != NULL) {
            if (left->val >= root->val)
                return false;
            
            if (!this->checkBinaryTree(left, std::numeric_limits<long>::min(), root->val))
                return false;
        }
        
        if (root->right != NULL) {
            if (right->val <= root->val)
                return false;
            
            if (!this->checkBinaryTree(right, root->val, std::numeric_limits<long>::max()))
                return false;
        }
        
        return true;
    }
    
    bool checkBinaryTree(TreeNode* node, long mi, long ma) {
        if (node == NULL)
            return true;
        
        cout << node->val << "," << mi << "," << ma << endl;
        
        if ((long)(node->val) > mi && (long)(node->val) < ma) {
            TreeNode* left = node->left;
            TreeNode* right = node->right;

            if (left != NULL) {
                if (this->checkBinaryTree(left, mi, min(ma, (long)(node->val))) == false)
                    return false;
            }

            if (right != NULL) {
                if (right->val <= node->val)
                    return false;

                if (this->checkBinaryTree(right, max(mi, (long)(node->val)), ma) == false)
                    return false;
            }

            return true;
        }
        
        return false;
    }
};