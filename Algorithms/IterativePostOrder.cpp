/* Using two Stacks */

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
   
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st1,st2;
        st1.push(root);
        while(!st1.empty())
        {
            TreeNode* curr = st1.top();
            st1.pop();
            st2.push(curr);
            if(curr->left) st1.push(curr->left);
            if(curr->right) st1.push(curr->right);
            
        }
        
        while(!st2.empty())
        {
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
        
        
    }
};


/* Using One Stack*/
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* curr = root->left;
        while(!st.empty())
        {
            if(curr!=NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                if(st.top()->right) curr = st.top()->right;
                else
                {
                    TreeNode* node = st.top();
                    st.pop();
                    ans.push_back(node->val);
                    while(!st.empty())
                    {
                        if(node!=st.top()->right) break;
                        node = st.top();
                        ans.push_back(node->val);
                        st.pop();
                    }
                    
                }
            }
        }
        return ans;
        
    }
};