class Solution {
public:
    //O(n) time -> number of nodes
    //O(d) space -> depth
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL){
            return NULL;
        }
        
        traversePostOrder(root);
        
        return root;
    }
    
    void traversePostOrder(TreeNode* root){
        if (root == NULL){
            return;
        }
         
        traversePostOrder(root->left);
        traversePostOrder(root->right);
        swap(&(root->left), &(root->right));
        
    }
    
    void swap(TreeNode** left, TreeNode** right){
        TreeNode* aux = *left;
        *left = *right;
        *right = aux;
    }
};
