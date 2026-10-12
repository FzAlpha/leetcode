// Last updated: 10/12/2026, 9:51:14 PM
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
    int result =0;

    pair<int,int> dfs(TreeNode* node){
        if(node == nullptr){
            return {0,0};
        }

        pair<int,int> left = dfs(node->left);
        pair<int,int> right = dfs(node->right);

        int currsum = left.first + right.first + node->val;
        int currcount = left.second + right.second + 1;

        if(node->val == currsum/currcount){
            result++;
        }

        return {currsum,currcount};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        result = 0;
        dfs(root);
        return result;
    }
};