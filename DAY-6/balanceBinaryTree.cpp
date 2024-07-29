#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;
        return max(height(root->left),height(root->right))+1;
    }
    bool solve(TreeNode* root){
        if(!root) return true;
        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(lh-rh)>1){
            return false;
        }
        return solve(root->left) && solve(root->right);
    }
    bool isBalanced(TreeNode* root) {
        return solve(root);
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    bool result = solution.isBalanced(root);
    if (result) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}