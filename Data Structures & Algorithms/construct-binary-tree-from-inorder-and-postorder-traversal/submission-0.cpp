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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> imap;
        for(int i=0;i<inorder.size();i++)
        {
            imap[inorder[i]]=i;
        }    

        TreeNode* root= buildTree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,imap);
        return root;
    }

    TreeNode* buildTree(vector<int>& postorder, int poststart,int postend, vector<int>& inorder, int instart, int inend, map<int,int>& imap){
    
        if(poststart>postend || instart>inend) return NULL;
    

    TreeNode* root=new TreeNode(postorder[postend]);
    int iroot=imap[root->val];
    int numsleft=iroot-instart;

    root->left=buildTree(postorder,poststart,poststart+numsleft-1,inorder,instart,iroot-1,imap);
    root->right=buildTree(postorder,poststart+numsleft,postend-1,inorder,iroot+1,inend,imap);
    return root;
    }
};