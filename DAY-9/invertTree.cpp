//link:-https://leetcode.com/problems/invert-binary-tree/

class Solution {
public:
void solve(TreeNode* root){
    if(!root){ //base case 
        return;
    }

    swap(root->left,root->right);
    solve(root->left);
    solve(root->right);

}
    TreeNode* invertTree(TreeNode* root) {
        
        solve(root);
        return root;
    }
};