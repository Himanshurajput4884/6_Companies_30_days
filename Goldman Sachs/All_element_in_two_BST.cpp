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
    void inorder(TreeNode * root, vector<int> &r){
        if(!root){
            return;
        }
        inorder(root->left, r);
        r.push_back(root->val);
        inorder(root->right, r);
    }

    vector<int> merge_sort(vector<int> &a, int n, vector<int> &b, int m){
        int i=0, j=0;
        vector<int> res;
        while(i<n and j<m){
            if(a[i] < b[j]){
                res.push_back(a[i++]);
            }
            else{
                res.push_back(b[j++]);
            }
        }
        while(i<n){
            res.push_back(a[i++]);
        }
        while(j<m){
            res.push_back(b[j++]);
        }
        return res;
    }



    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        inorder(root1, a), inorder(root2, b);
        return merge_sort(a, a.size(), b, b.size());
    }
};
