// Last updated: 10/12/2026, 9:53:45 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long int>> q;
        q.push({root, 0});
        int maxwidth = 0;

        while (q.size() > 0) {
            int currlevelsize = q.size();
            unsigned long long int stindx = q.front().second;
            unsigned long long int endindx = q.back().second;

            maxwidth = max(maxwidth,(int)(endindx - stindx + 1));

            for (int i = 0; i < currlevelsize; i++) {
                auto curr = q.front();
                q.pop();

                if (curr.first->left) {
                    q.push({curr.first->left, curr.second * 2 + 1});
                }
                if (curr.first->right) {
                    q.push({curr.first->right, curr.second * 2 + 2});
                }
            }
        }

        return maxwidth;
    }
};