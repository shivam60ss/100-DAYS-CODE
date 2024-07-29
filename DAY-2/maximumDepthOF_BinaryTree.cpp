#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int solve(TreeNode* root){
        if(!root) return 0;

        if(root->left==NULL && root->right==NULL){
            return 1;

        }

        int lh = solve(root->left);
        int rh = solve(root->right);

        return max(lh,rh)+1;
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;

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

    cout << "Max depth of the tree is: " << solution.maxDepth(root) << endl;

    return 0;
}