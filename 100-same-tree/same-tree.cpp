/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
     private:
    void inorder(TreeNode* root, vector<int> &Traverse){
        if(root==NULL)
        return;
    
        
        inorder(root->left, Traverse);
        Traverse.push_back(root->val);
        inorder(root->right, Traverse);

        if(root->left==NULL || root->right==NULL)
        Traverse.push_back(-1);       

    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> pTraverse, qTraverse;
        inorder(p, pTraverse);
        inorder(q, qTraverse);
        
        return pTraverse==qTraverse;
    }
};