#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
    node(int d){
        this->data=d;
        this->left = NULL;
        this->right=NULL;
    }
};
node* buildTree(node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root= new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}
// inorder traversal - [LNR]
void inorder(node* root,int &cnt){
    //base case
    if(root==NULL){
        return;
    }
    inorder(root->left,cnt);
    //leaf node
    if(root->left==NULL && root->right==NULL){
        cnt++;
    }
    inorder(root->right,cnt);
}
// no. of leaf nodes
int noOfLeafNodes(node* root){
    int cnt=0;
    inorder(root,cnt);
    return cnt;
}
// height of BT
int height(node* root){
    // base case
    if(root==NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int ans= max(left,right)+1;
    return ans;
}

// Diameter of BT -- TC: O(n*n) & SC: O(n)
int diameter(node* root){
    //base case
    if(root == NULL){
        return 0;
    }
    int opt1 = diameter(root->left);
    int opt2 = diameter(root->right);
    int opt3 = height(root->left) + height(root->right) + 1;
    int ans = max(opt1, max(opt2, opt3));
    return ans;
}
// diameter of BT -- Tc/Sc: O(n)
pair<int,int> diameterFast(node* root){
    //base case
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);
    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + right.second + 1;
    pair<int,int> ans;
    ans.first = max(opt1, max(opt2, opt3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
// check for balance tree --Tc: O(n*n)
bool Balanced(node* root){
    //base case 
    if(root==NULL){
        return true;
    }
    bool left = Balanced(root->left);
    bool right = Balanced(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <=1;
    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }
}
// check for balance tree --tc: O(n)
pair<bool,int> BalancedFast(node* root){
    if(root==NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    pair<int,int> left = BalancedFast(root->left);
    pair<int,int> right = BalancedFast(root->right); 
    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second - right.second) <=1;
    pair<bool,int> ans;
    ans.second = max(left.second,right.second)+1;
    if(leftAns && rightAns && diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }
    return ans;
}
// check for identical
bool Identical(node* r1, node* r2){
    //base case
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if(r1!=NULL && r2==NULL){
        return false;
    }
    if(r1==NULL && r2!=NULL){
        return false;
    }
    bool left = Identical(r1->left,r2->left);
    bool right = Identical(r1->right,r2->right);
    bool value = r1->data == r2->data;
    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
}
// sum tree
pair<bool,int> SumTree(node* root){
    //base case
    if(root==NULL){
        pair<bool,int> p = make_pair(true,0);
        return p; 
    }
    //leaf node
    if(root->left==NULL && root->right==NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p; 
    }
    pair<bool,int> leftAns = SumTree(root->left);
    pair<bool,int> rightAns = SumTree(root->right);
    bool left = leftAns.first;
    bool right = rightAns.first;
    bool condn = root->data == leftAns.second + rightAns.second;
    pair<bool,int> ans;
    if(left && right && condn){
        ans.first = true;
        ans.second = root->data + leftAns.second + rightAns.second;
    } 
    else{
        ans.first = false;
    }
    return ans;
}
int main(){
    node* root = NULL;
    // creating tree
    root = buildTree(root);
    // no. of leaf nodes
    cout<<"No. of leaf nodes: "<<noOfLeafNodes(root)<<endl;
    cout<<"Height of BTREE is: "<<height(root)<<endl;
    cout<<"Diameter of BTree is: "<<diameter(root)<<" and through fast method is: "<<diameterFast(root).first<<endl;
    cout<<"Is Tree Balanced: "<<Balanced(root)<<" and through fast method is: "<<BalancedFast(root).first<<endl;
    cout<<"Tree is identical: "<<Identical(root,root)<<endl;
    cout<<"Given tree is Sum Tree: "<<SumTree(root).first<<endl;
    return 0;
}