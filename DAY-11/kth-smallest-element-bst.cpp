//link:-https://leetcode.com/problems/kth-smallest-element-in-a-bst/

class Solution {
public:
int count = 0;
int out = 0;
void solve(TreeNode* root,int k){
    if(root->left!=NULL){
        solve(root->left,k);
    }
    count++;
    //ager count is equal to k then return root->val 
    if(count==k){
        out = root->val;
    }
    if(root->right!=NULL){
        solve(root->right,k);
    }

}
    int kthSmallest(TreeNode* root, int k) {
        solve(root,k);
        return out; //root->val
        
        
    }
};