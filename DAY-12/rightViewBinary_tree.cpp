
link:-https://leetcode.com/problems/binary-tree-right-side-view/
//this the leetcode problem no 199 // rightview binary tree
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans; // Vector to store the right side view of the tree
        if(!root) return ans; //return an empty vector if the root is NULL

        queue<TreeNode*> q; // Queue to perform level-order traversal (BFS)
        q.push(root); // Start with the root node


        while(!q.empty()){
            int n = q.size();
            for(int i =0;i<n;i++){
                TreeNode* curr = q.front();// Get the front node in the queue
                q.pop();

                if(i==n-1){
                    ans.push_back(curr->val);

                }
                // Add the left child to the queue if it exists
                if(curr->left != NULL){
                    q.push(curr->left);
                }
                // Add the right child to the queue if it exists
                if(curr->right != NULL){
                    q.push(curr->right);
                }
                
            }
        }
        
        return ans;
    }
};