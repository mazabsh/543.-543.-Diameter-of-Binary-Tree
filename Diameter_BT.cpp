#include<iostream> 
#include<algorithm> 

using namespace std; 

class TreeNode{
public: 
      int val; 
      TreeNode* left; 
      TreeNode* right; 
      TreeNode(): val(0), left(NULL), right(NULL){}
      TreeNode(int _val): val(_val), left(NULL), right(NULL){}
      TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right){}
};
class Solution{
public: 
     int ans =0; 
     int diameterOfBinaryTree(TreeNode* root){
       dfs(root); 
       return ans;
     }
     int dfs(TreeNode* root){
       if(!root) return 0; 
       int l = dfs(root->left); 
       int r = dfs(root->right); 
       ans = max(ans, l+r); 
       return 1+max(l,r); 
     }
     
};
int main(){
  TreeNode* root = new TreeNode(1); 
  root->left = new TreeNode(2); 
  root->right = new TreeNode(3); 
  root->left->left= new TreeNode(4); 
  root->left->right = new TreeNode(5); 
  Solution sol; 
  cout << sol.diameterOfBinaryTree(root) << endl; 
  return 0; 
}
