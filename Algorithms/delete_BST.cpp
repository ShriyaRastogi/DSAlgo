/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*Two Cases:
    Case A: The to be deleted node has only one or no child
    Case B: The to be deleted node has two children. For this, apply CaseA for Inorder Successor
    */
    TreeNode* caseA(TreeNode* root, TreeNode* par, TreeNode* loc)
    {
        if(root==NULL) return NULL;
        TreeNode* child = NULL;
        if(loc->left == NULL && loc->right == NULL) child = NULL;
        else
        {
            if(loc->left) child = loc->left;
            else child = loc->right;
        }
        if(par)
        {
            if(par->left == loc) par->left = child;
            else par->right = child;
        }
        else 
        {
           // if(child==NULL) cout<<"done"<<endl;
            root = child;
        }
        
        return root;
    }
    TreeNode* caseB(TreeNode* root, TreeNode* par, TreeNode* loc)
    {
        if(root==NULL) return NULL;
        TreeNode* suc = loc->left;
        TreeNode* psuc = loc;
        while(suc->right)
        {
            psuc = suc;
            suc = suc->right;
        }
        root = caseA(root, psuc, suc);
        if(par)
        {
            if(par->left == loc) par->left = suc;
            else par->right = suc;
        }
        else root = suc;
        suc->left = loc->left;
        suc->right = loc->right;
        return root;
    }
    TreeNode* search(TreeNode* root, TreeNode* par, TreeNode* curr, int &key)
    {
        if(curr==NULL) return root; 
        if(curr->val == key)
        {
            if(curr->left && curr->right) root = caseB(root,par,curr);
            else root = caseA(root,par,curr);
        }
        root = search(root, curr, curr->left,key);
        root = search(root, curr, curr->right, key);
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        root = search(root,NULL, root,key);
        return root;
        
    }
};