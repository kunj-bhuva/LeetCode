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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result1;
        inorderTraversal(root1, result1);
        vector<int> result2;
        inorderTraversal(root2, result2);

        vector<int> result;
        int i = 0, j = 0;
        while (i < result1.size() && j < result2.size()) {
            if (result1[i] <= result2[j]) {
                result.push_back(result1[i]);
                i++;
            } else {
                result.push_back(result2[j]);
                j++;
            }
        }

        while (i < result1.size()) {
            result.push_back(result1[i]);
            i++;
        }

        while (j < result2.size()) {
            result.push_back(result2[j]);
            j++;
        }

        return result;
    }

private:
    void inorderTraversal(TreeNode* root, vector<int>& result) {
        if (root == nullptr)
            return;

        inorderTraversal(root->left, result);
        result.push_back(root->val);
        inorderTraversal(root->right, result);
    }
};
