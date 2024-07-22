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
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        unordered_map<int, int> frequencyMap;  // Use unordered_map to count frequencies
        int maxCount = 0;
        
        // Perform in-order traversal and count frequencies
        inOrderTraversal(root, frequencyMap, maxCount);
        
        // Find all the modes
        for (const auto& entry : frequencyMap) {
            if (entry.second == maxCount) {
                result.push_back(entry.first);
            }
        }
        
        return result;
    }

private:
    // Helper function for in-order traversal
    void inOrderTraversal(TreeNode* node, unordered_map<int, int>& frequencyMap, int& maxCount) {
        if (node == nullptr) return;  // Base case: empty node
        
        // Traverse left subtree
        inOrderTraversal(node->left, frequencyMap, maxCount);
        
        // Process current node
        frequencyMap[node->val]++;
        maxCount = max(maxCount, frequencyMap[node->val]);
        
        // Traverse right subtree
        inOrderTraversal(node->right, frequencyMap, maxCount);
    }
};