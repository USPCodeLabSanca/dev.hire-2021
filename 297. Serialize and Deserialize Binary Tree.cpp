//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

class Codec {
public:
    
    // Encodes a tree to a single string.
    //O(n) time -> n number of nodes
    //O(1) space
    string serialize(TreeNode* root) {
        string data = "";
        
        encode(root, data);
        
        return data;
    }
    
    void encode(TreeNode* root, string& data){
        if (root == NULL){
            data += " ";
            return;
        }
        
        data += to_string(root->val);
        data += "*";
        
        encode(root->left, data);
        encode(root->right, data);
    }
    
    // Decodes your encoded data to tree.
    //O(s) time -> s the length of the string
    //O(1) space
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        int index = 0;
        
        decode(root, data, index);
        
        return root;
    }
    
    void decode(TreeNode*& root, string data, int& index){
        if (index >= data.size()){
            return;
        }
        
        if (data[index] != ' '){
            root = new TreeNode();
            root->val = getValue(index, data);
        } else {
            root = NULL;
            index++;
            return;
        }
        
        decode(root->left, data, index);
        decode(root->right, data, index);
    }
    
    int getValue(int &index, string data){
        int quant = data.find("*", index);
        int value = stoi(data.substr(index, quant));
        index = quant + 1; //to skip asterisk
        
        return value;
    }
};
