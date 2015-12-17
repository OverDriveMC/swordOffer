/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        if(pre.size() !=in.size()){
            throw "invalid input!";
        }
        return buildBinaryTree(pre,0,pre.size()-1,in,0,in.size()-1);
    }
/**
*前序: 中前后
*中序: 前中后
*/
    TreeNode *buildBinaryTree(vector<int>pre,int pstart,int plst,vector<int>in,int istart,int ilst){
/*
        cout<<"pre:";
        for(int i=pstart;i<=plst;i++){
            cout<<(char)pre[i]<<" ";
        }
        cout<<endl;
        cout<<"in:";
        for(int i=istart;i<=ilst;i++){
            cout<<(char)in[i]<<" ";
        }
        cout<<endl;
 
*/
        TreeNode *root=new TreeNode(pre[pstart]);
        if(pstart==plst){
            return root;
        }
        int pos=-1;
        for(int i=istart;i<=ilst;i++){
            if(pre[pstart]==in[i]){
                pos=i;
            }
        }
        if(pos==-1){
            throw "invalid input!";
        }
 
        int nplst=pstart+pos-istart;
        if(nplst>=pstart+1 &&  (pos-1 >=istart)){
            root->left=buildBinaryTree(pre,pstart+1,nplst ,in,istart,pos-1);
        }
        int ipstart=pstart+pos-istart+1;
        if(ipstart<=plst && (pos+1 <=ilst)){
            root->right=buildBinaryTree(pre,ipstart,plst,in,pos+1,ilst);
        }
        return root;
    }
};

