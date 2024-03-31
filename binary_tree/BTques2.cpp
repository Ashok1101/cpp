#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
// zigzag traversal
vector<int> zigzag(node* root){
    vector<int> result;
    if(root==NULL){
        return result;
    }
    queue<node*>q;
    q.push(root);
    bool LeftToRight= true;
    while(!q.empty()){
        int size=q.size();
        vector<int> ans(size);
        //level process
        for(int i=0;i<size;i++){
            node* frontnode = q.front();
            q.pop();
            //normal insert or reverse insert
            int index= LeftToRight ? i: size-i-1;
            ans[index] = frontnode->data;
            if(frontnode->left){
                q.push(frontnode->left);
            }
            if(frontnode->right){
                q.push(frontnode->right);
            }
        }
        //direction change karni h
        LeftToRight = !LeftToRight;
        for(auto i:ans){
            result.push_back(i);
        }
    }
    return result;
}
//Boundry traversal
void traverseLeft(node* root, vector<int> &ans) {
    //base case
    if( (root == NULL) || (root->left == NULL && root->right == NULL) )
        return ;
        
    ans.push_back(root->data);
    if(root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
        
}

void traverseLeaf(node* root, vector<int> &ans) {
    //base case
    if(root == NULL)
        return ;
        
    if(root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }
    
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
    
}

void traverseRight(node* root, vector<int> &ans) {
    //base case
    if( (root == NULL) || (root->left == NULL && root->right == NULL) )
        return ;
    
    if(root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);
        
    //wapas aagye
    ans.push_back(root->data);
        
}

vector <int> boundary(node *root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;
        
    ans.push_back(root->data);
    
    //left part print/store
    traverseLeft(root->left, ans);
    
    //traverse Leaf nodes

    //left subtree
    traverseLeaf(root->left, ans);
    //right subtree
    traverseLeaf(root->right, ans);

    //traverse right part
    traverseRight(root->right, ans);
    return ans;
}
// vertical traversal
vector<int> verticalOrder(node* root)
{
    map<int, map<int,vector<int> > > nodes;
    queue< pair<node*, pair<int,int> > > q;
    vector<int> ans;
    
    if(root == NULL)
        return ans;
        
    q.push(make_pair(root, make_pair(0,0)));
    
    while(!q.empty()) {
        pair<node*, pair<int,int> > temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;
        
        nodes[hd][lvl].push_back(frontNode->data);
        
        if(frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1) ));
            
        if(frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
    }
    
    for(auto i: nodes) {
        
        for(auto j:i.second) {
            
            for(auto k:j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}
//top view
vector<int>topView(node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    map<int,int>topnode;
    queue<pair<node*, int>>q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int>temp = q.front();
        q.pop();
        node* frontnode = temp.first;
        int hd = temp.second;
        //if one value is present for a HD, then do nothing
        if(topnode.find(hd)==topnode.end()){
            topnode[hd] = frontnode->data;
        }
        if(frontnode->left){
            q.push(make_pair(frontnode->left,hd-1));
        }
        if(frontnode->right){
            q.push(make_pair(frontnode->right,hd+1));
        }
    }
    for(auto i:topnode){
        ans.push_back(i.second);
    }
    return ans;
}
// Bottom View
vector<int>bottomView(node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    map<int,int>topnode;
    queue<pair<node*, int>>q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int>temp = q.front();
        q.pop();
        node* frontnode = temp.first;
        int hd = temp.second;
        topnode[hd] = frontnode->data;
        if(frontnode->left){
            q.push(make_pair(frontnode->left,hd-1));
        }
        if(frontnode->right){
            q.push(make_pair(frontnode->right,hd+1));
        }
    }
    for(auto i:topnode){
        ans.push_back(i.second);
    }
    return ans;
}
//left view
void solve(node* root, vector<int> &ans, int level) {
    //base case
    if(root == NULL)
        return ;
       
    //we entered into a new level    
    if(level == ans.size())
        ans.push_back(root->data);
        
    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}

vector<int> leftView(node *root)
{
   vector<int> ans;
   solve(root, ans, 0);
   return ans;
}
//right view
void solve1(node* root, vector<int> &ans, int level) {
    //base case
    if(root == NULL)
        return ;
       
    //we entered into a new level    
    if(level == ans.size())
        ans.push_back(root->data);
        
    solve1(root->right, ans, level+1);
    solve1(root->left, ans, level+1);
}

vector<int> rightView(node *root)
{
   vector<int> ans;
   solve1(root, ans, 0);
   return ans;
}
// Diagonal traversal
vector<int> diagonalOrder(node* root)
{
    map<int, map<int,vector<int> > > nodes;
    queue< pair<node*, pair<int,int> > > q;
    vector<int> ans;
    
    if(root == NULL)
        return ans;
        
    q.push(make_pair(root, make_pair(0,0)));
    
    while(!q.empty()) {
        pair<node*, pair<int,int> > temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;
        
        nodes[hd][lvl].push_back(frontNode->data);
        
        if(frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd+1, lvl+1) ));
        if(frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd, lvl+1)));    
    }
    
    for(auto i: nodes) {
        
        for(auto j:i.second) {
            
            for(auto k:j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}
int main(){
    node* root = NULL;
    // creating tree
    root = buildTree(root);
    // zigzag traversal
    cout<<"zigzag traversal: ";
    for(int i:zigzag(root)){
        cout<<i<<" ";
    }
    cout<<endl;
    // Boundary traversal
    cout<<"Boundary traversal: ";
    for(int i:boundary(root)){
        cout<<i<<" ";
    }
    cout<<endl;
    //vertical traversal
    cout<<"vertical traversal: ";
    for(int i:verticalOrder(root)){
        cout<<i<<" ";
    }
    cout<<endl;
    //top view
    cout<<"Top View: ";
    for(int i:topView(root)){
        cout<<i<<" ";
    }
    cout<<endl;
    //bottom view
    cout<<"Bottom View: ";
    for(int i:bottomView(root)){
        cout<<i<<" ";
    }
    cout<<endl;
    //left view
    cout<<"left View: ";
    for(int i:leftView(root)){
        cout<<i<<" ";
    }
    cout<<endl;
    //right view
    cout<<"right View: ";
    for(int i:rightView(root)){
        cout<<i<<" ";
    }
    cout<<endl;
    //diagonal traversal
    cout<<"diagonal traversal: ";
    for(int i:diagonalOrder(root)){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}