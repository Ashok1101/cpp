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
// level wise
void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp==NULL){ //prev level complete traverse ho chuka hai
            cout<<endl;
            if(!q.empty()){ // queue has still some child nodes
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
//reverse level order traversal
void reverseLevelOrderTraversal(node* root){
    queue<node*> q;
    stack<node*> s;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp == NULL){
            s.push(NULL);
        } 
        else{
            s.push(temp);
            if(temp->right){
                q.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
            }
        }
        // Check if all nodes of the current level have been processed
        if(q.empty()){
            while(!s.empty()){
                node* reverseTemp = s.top();
                s.pop();
                if(reverseTemp != NULL){
                    cout<<reverseTemp->data<<" ";
                }
            }
            cout<<endl;
            // If there are more levels, add a marker to the queue
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }
}
// inorder traversal - [LNR]
void inorder(node* root){
    //base case
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
// preorder traversal - [NLR]
void preorder(node* root){
    //base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
// postorder traversal - [LRN]
void postorder(node* root){
    //base case
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
// input order in level wise
void buildfromLevelOrder(node* root){
    queue<node*> q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        cout<<"Enter left node for: "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!= -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter right node for: "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData !=-1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
int main(){
    node* root = NULL;
    // creating tree
    root = buildTree(root);
    // level order
    levelOrderTraversal(root); // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    reverseLevelOrderTraversal(root);
    //inorder
    cout<<"inorder traversal is: ";
    inorder(root);
    //preorder
    cout<<endl<<"preorder traversal is: ";
    preorder(root);
    //postorder
    cout<<endl<<"postorder traversal is: ";
    postorder(root);
    cout<<endl;
    // input order in level wise
    buildfromLevelOrder(root); // 1 3 7 11 5 17 -1 -1 -1 -1 -1 -1 -1  
    levelOrderTraversal(root);
    return 0;
}