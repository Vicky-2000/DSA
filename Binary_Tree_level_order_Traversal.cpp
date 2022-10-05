class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
       vector<int> temp;
        while(!q.empty()){
        int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* top=q.front();
                q.pop();
                temp.push_back(top->val);
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
        //
    }
};
