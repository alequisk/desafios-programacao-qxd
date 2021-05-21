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
 
 /**
* Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
* Status: AC | 16ms | 24MB
* */
 
class Solution {
public:
    bool hasAns = false;
    int ans = -1, K = 0, t; 
    int kthSmallest(TreeNode* root, int k) {
      t = k;
      solve(root);
      return ans;
    }
  
    void solve(TreeNode* node) {
      if (!hasAns) {
        if (node->left != nullptr) {
          solve(node->left);
        }

        K += 1;
        
        if (K == t) {
          ans = node->val;
          hasAns = true;
          return;
        }
        
        if (node->right != nullptr) {
          solve(node->right);
        }
      }
    }
};
