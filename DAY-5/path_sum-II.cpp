#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution class with the pathSum function
//------------------------------------------------------------------------leetcode
class Solution {
public:
    void solve(TreeNode* root, int target, vector<int>& path, vector<vector<int>>& result) {
        if (!root) return;
        
        path.push_back(root->val);
        
        if (!root->left && !root->right && target == root->val) {
            result.push_back(path);
        } else {
            solve(root->left, target - root->val, path, result);
            solve(root->right, target - root->val, path, result);
        }
        
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        solve(root, targetSum, path, result);
        return result;
    }
};
//---------------------------------------------------------------------------

// Main function to test the code
int main() {
    // Construct the binary tree
    // Example Tree:
    //       5
    //      / \
    //     4   8
    //    /   / \
    //   11  13  4
    //  /  \      \
    // 7    2      1
    
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    // Target sum
    int targetSum = 22;

    // Create Solution object and call pathSum
    Solution solution;
    vector<vector<int>> result = solution.pathSum(root, targetSum);

    // Print the result
    cout << "Paths with sum " << targetSum << " are:\n";
    for (const auto& path : result) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Clean up memory
    // (In real code, use smart pointers or a more sophisticated memory management strategy)
    // Delete nodes to avoid memory leaks (not shown here for brevity)

    return 0;
}
