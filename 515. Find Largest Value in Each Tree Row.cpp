//https://leetcode.com/problems/find-largest-value-in-each-tree-row/
class Solution {
public:
    //O(n) time and O(1) space
    vector<int> largestValues(TreeNode* root) {
        vector<int> arr;
        
        traverse(root, arr, 0);
        
        return arr;
    }
    
    void traverse(TreeNode* root, vector<int>& arr, int row){
        if (root == NULL)
            return;
        
        if (arr.size() < row + 1){
            arr.resize(row + 1);
            arr[row] = root -> val;
        }
        
        arr[row] = max(arr[row], root->val);
        
        traverse(root->left, arr, row + 1);
        traverse(root->right, arr, row + 1);
    }
};
