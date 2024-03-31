#include<iostream>
#include <utility>
#include<vector>
using namespace std;
class node{
    public:
        int data;
        node*left;
        node*right;
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
node* insertIntoBST(node* root,int d){
    //base case
    if(root == NULL){
        root = new node(d);
        return root;
    }
    if(d > root->data){
        //right part me insert karna h
        root->right = insertIntoBST(root->right,d);
    }
    else{
        //left part me insert karna h
        root->left = insertIntoBST(root->left,d);
    }
    return root;
}
void takeInput(node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}
// validate BST
bool isBST(node* root, int min, int max){
    //base case
    if(root == NULL){
        return true;
    }
    if(root->data >= min && root->data <= max){
        bool left = isBST(root->left,min,root->data);
        bool right = isBST(root->right,root->data,max);
        return left && right;
    }
    else{
        return false;
    }
}
// k-smallest element
int k_smallest(node* root,int i,int k){
    //base case
    if(root == NULL){
        return -1;
    }
    //L
    int left = k_smallest(root->left,i,k);
    if(left != -1){
        return left;
    }
    //N
    i++;
    if(i==k){
        return root->data;
    }
    //R
    return k_smallest(root->right,i,k);
}
//predecessor and successor
pair<int,int> predsucc(node* root,int key){
    //find key
    node* temp=root;
    int pred =-1;
    int succ =-1;
    while(temp->data != key){
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
        }
        else{
            pred = temp->data;
            temp = temp->right; 
        }
    }
    //pred
    node* leftTree = temp->left;
    while(leftTree != NULL){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }
    //succ
    node* rightTree = temp->right;
    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
    return {pred,succ};
}
// LCA in BST (least common ancestor)
node* LCA(node* root, node* P,node* Q){
    //base case
    if(root == NULL){
        return NULL;
    }
    if(root->data < P->data && root->data < Q->data){
        return LCA(root->right,P,Q);
    }
    if(root->data > P->data &&  root->data >Q->data){
        return LCA(root->left,P,Q);
    }
    else{
        return root;
    }
}
//two sum in BST
void inorder(node* root,vector <int> &in){
    if(root == NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
void twoSum(node* root,int target){
    vector<int> inorderval;
    inorder(root,inorderval);
    int i=0,j= inorderval.size()-1;
    while(i<j){
        int sum = inorderval[i] + inorderval[j];
        if(sum == target){
            cout<<"There exists two nodes whose sum is "<<target;
            break;
        }
        else if(sum > target){
            j--;
        }
        else{
            i++;
        }
    }
}
// Flatten BST to sorted list
void print(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->right;
    }
    cout<<endl;
}
void flatten(node* root){
    vector <int> inorderval;
    inorder(root, inorderval);
    int n = inorderval.size();
    node* newroot = new node(inorderval[0]);
    node* curr = newroot;
    //2nd step
    for(int i=1;i<n;i++){
        node* temp= new node(inorderval[i]);
        curr->left = NULL;
        curr->right =temp;
        curr = temp;
    }
    //3rd step
    curr->left = NULL;
    curr->right = NULL;
    print(newroot);
}
// BST to balanced BST
void inorderToBST(int s,int e, vector<int> in){
    //base case
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    node* root = new node(in[mid]);
    root->left = inorderToBST(s,mid-1,in);
    root->right = inorderToBST(mid+1,e,in);
    print(root);
}
void balancedBST(node* root){
    vector<int> inorderval;
    //store inorder
    inorder(root,inorderval);
    inorderToBST(0,inorderval.size()-1,inorderval);
}
// largest BST subtree
class info{
    public: 
    int maxi;
    int mini;
    bool isBST;
    int size;
};
info solve(node* root,int &ans){
    //base case
    if(root==NULL){
        return {INT8_MIN,INT16_MAX,true,0};
    }
    info left = solve(root->left,ans);
    info right = solve(root->right,ans);
    info currnode;
    currnode.size = left.size + right.size + 1;
    currnode.maxi = max(root->data,right.maxi);
    currnode.mini = min(root->data,left.mini);
    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        currnode.isBST = true;
    }
    else{
        currnode.isBST = false;
    }
    //ans update
    if(currnode.isBST){
        ans = max(ans,currnode.size);
    }
    return currnode;
}
int largestBST(node* root){
    int maxsize = 0;
    info temp = solve(root, maxsize);
    return maxsize;
}
int main(){
    node* root=NULL;
    // BST insertion - O(logn)
    cout<<"Enter data to create BST"<<endl;
    takeInput(root);
    // validate BST
    cout<<"given BT is BST or not: "<<isBST(root,INT8_MIN,INT8_MAX)<<endl;
    int i=0,k=3;
    cout<<"k-smallest element in BST is: "<<k_smallest(root,i,k)<<endl;
    cout<<"precedesor and successor of key "<<k<<" is: "<<predsucc(root,k).first<<" and "<<predsucc(root,k).second<<endl;
    node* P = new node(1);
    node* Q = new node(3);
    cout<<"LCA of nodes "<<P->data<<" & "<<Q->data<<" is: "<<LCA(root,P,Q)->data<<endl;
    //two sum
    int target =5;
    twoSum(root,target);
    cout<<endl;
    //flatten bst
    flatten(root);
    //balanced BST
    balancedBST(root);
    //largest BST
    cout<<"Largest BST has "<<largestBST(root)<<" nodes."<<endl;
}