#include <iostream>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int height(TreeNode* root){
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    void solve(TreeNode* root, int& ans){
        if (!root) return;
        int lh = height(root->left);
        int rh = height(root->right);
        ans = max(ans, lh + rh);

        solve(root->left, ans);
        solve(root->right, ans);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};

// Function to create a simple binary tree for testing
TreeNode* createTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

int main() {
    // Create an instance of the Solution class
    Solution solution;
    
    // Create a binary tree
    TreeNode* root = createTree();
    
    // Calculate the diameter of the binary tree
    int diameter = solution.diameterOfBinaryTree(root);
    
    // Print the result
    cout << "Diameter of the binary tree: " << diameter << endl;

    // Cleanup dynamically allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
