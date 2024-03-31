#include<iostream>
#include<queue>
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
bool SearchInBST(node* root,int x){
    //base case
    if(root == NULL){
        return false;
    }
    if(root->data ==x){
        return true;
    }
    if(root->data > x){
        return SearchInBST(root->left,x);
    }
    else{
        return SearchInBST(root->right,x);
    }
}
//min value
node* minval(node* root){
    node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
// deletion
node* deleteFromBST(node* root,int val){
    //base case
    if(root == NULL){
        return root;
    }
    else if(root->data == val){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //1 child
        if(root->left != NULL && root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minval(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if(root->data > val){
        root->left = deleteFromBST(root->left,val);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right,val);
        return root;
    }
}
int main(){
    node* root=NULL;
    // BST insertion - O(logn)
    cout<<"Enter data to create BST"<<endl;
    takeInput(root);
    cout<<"Printing BST:"<<endl;
    levelOrderTraversal(root);
    // BST search
    int x;
    cin>>x;
    cout<<x<<" is present in BST?:"<<SearchInBST(root,x)<<endl;
    // Deletion
    root = deleteFromBST(root,3);
    levelOrderTraversal(root);
    return 0;
}
