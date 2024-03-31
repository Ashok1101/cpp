#include<iostream>
#include<vector>
#include <bits/stdc++.h>
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
//bloodline
void solve(node* root, int sum, int &maxSum, int len, int &maxLen) {
    //base case
    if( root == NULL ) {
        
        if(len > maxLen) 
        {
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen) 
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }
    
    sum = sum + root->data;
    
    solve(root->left, sum, maxSum, len+1, maxLen);
    solve(root->right, sum, maxSum, len+1, maxLen);

}
int sumOfLongRootToLeafPath(node *root)
{
    int len = 0;
    int maxLen = 0;
    int sum = 0;
    int maxSum = 0;
    solve(root, sum, maxSum, len, maxLen);
    return maxSum;
}
// LOWEST COMMON ANCESTORS IN A BT  -Tc & Sc:O(n)
node* lca(node* root,int n1, int n2){
    //base case
    if(root==NULL){
        return NULL;
    }
    if(root->data ==n1 || root->data ==n2){
        return root;
    }
    node* leftAns = lca(root->left, n1, n2);
    node* rightAns = lca(root->right, n1, n2);
    if(leftAns != NULL && rightAns != NULL){
        return root;
    }
    else if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }
    else{
        return NULL;
    }
}
// K Sum Path
void solve1(node* root, int k, int &count, vector<int> path) {
    //base case
    if(root == NULL)
        return ;
    
    path.push_back(root->data);
    
    //left
    solve1(root->left, k, count, path);
    //right
    solve1(root->right, k, count, path);
    
    //check for K Sum
    
    int size = path.size();
    int sum = 0;
    for(int i = size-1; i>=0; i--)  {
        sum += path[i];
        if(sum == k)
            count++;
    }
    
    path.pop_back();
}
int sumK(node *root,int k){
    vector<int> path;
    int count = 0;
    solve1(root, k, count, path);
    return count;
}
// kth Ancestor
node* solve(node* root, int &k, int n1) {
    //base case
    if(root == NULL)
        return NULL;
        
    if(root->data == n1) 
    {
        return root;
    }
    
    node* leftAns = solve(root->left, k, n1);
    node* rightAns = solve(root->right, k, n1);


    //wapas
    if(leftAns != NULL && rightAns == NULL) 
    {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL) {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
    

}
int kthAncestor(node *root, int k, int n1)
{
    node* ans = solve(root, k, n1);
    if(ans == NULL || ans->data == n1)
        return -1;
    else
        return ans->data;
}
// max sum of non-adjacent nodes
pair<int,int> solve(node* root) {
    //base case
    if(root == NULL) {
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    
    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);
    
    pair<int,int> res;
    
    res.first = root->data + left.second + right.second;
    
    res.second = max(left.first, left.second) + max(right.first, right.second);
    
    return res;
    
}
int getMaxSum(node *root) 
{
    pair<int,int> ans = solve(root);
    return max(ans.first, ans.second);
}
// Construct tree from Inorder & Preorder
int findPosition(int inorder[],int element,int n){
    for(int i=0;i<n;i++){
        if(inorder[i]==element)
            return i;
    }
    return -1;
}
node* solve2(int inorder[],int preorder[],int &index,int inorderStart,int inorderEnd,int n){
    //base case
    if(index >= n || inorderStart > inorderEnd){
        return NULL;
    }
    int element= preorder[index++];
    node* temp = new node(element);
    int position = findPosition(inorder, element, n);
    //recursive calls
    temp->left = solve2(inorder,preorder,index,inorderStart,position-1,n);
    temp->right = solve2(inorder,preorder,index,position+1,inorderEnd,n);
    cout<<temp->data<<" ";
    return temp;
}
void buildtree(int inorder[],int preorder[],int n){
    int preorderIndex = 0;
    // node* ans = 
    solve2(inorder,preorder,preorderIndex,0,n-1,n);
    // return ans;
}
// Construct tree from Inorder & Postorder
int FindPosition(int inorder[],int element,int n){
    for(int i=0;i<n;i++){
        if(inorder[i]==element)
            return i;
    }
    return -1;
}
node* solve3(int inorder[],int postorder[],int &index,int inorderStart,int inorderEnd,int n){
    //base case
    if(index < 0 || inorderStart > inorderEnd){
        return NULL;
    }
    int element= postorder[index--];
    node* temp = new node(element);
    int position = FindPosition(inorder, element, n);
    //recursive calls
    temp->right = solve3(inorder,postorder,index,position+1,inorderEnd,n);
    temp->left = solve3(inorder,postorder,index,inorderStart,position-1,n);
    cout<<temp->data<<" ";
    return temp;
}
void buildtree1(int inorder[],int postorder[],int n){
    int postorderIndex = n-1;
    // node* ans = 
    solve3(inorder,postorder,postorderIndex,0,n-1,n);
    // return ans;
}
// Burning Tree   -Tc & Sc: O(n)
node* createParentMapping(node* root,int target,map<node*,node*> &nodeToParent){
    node* res = NULL;
    queue<node*> q;
    q.push(root);
    nodeToParent[root]= NULL;
    while(!q.empty()){
        node* front = q.front();
        q.pop();
        if(front->data == target){
            res= front;
        }
        if(front->left){
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if(front->right){
            nodeToParent[front->right]= front;
            q.push(front->right);
        }
    }
    return res;
}
int burnTree(node* root, map<node*,node*> &nodeToParent){
    map<node*,bool> visited;
    queue<node*> q;
    q.push(root);
    visited[root] = true;
    int ans=0;
    while(!q.empty()){
        bool flag =0;
        int size = q.size();
        for(int i=0;i<size;i++){
            // process neighbouring nodes
            node* front = q.front();
            q.pop();
            if(front->left && !visited[front->left]){
                flag =1;
                q.push(front->left);
                visited[front->left] =1;
            }
            if(front->right && !visited[front->right]){
                flag =1;
                q.push(front->right);
                visited[front->right] =1;
            }
            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                flag =1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] =1;
            }
        }
        if(flag == 1){
            ans++;
        }
    }
    return ans;
}
int minTime(node* root, int target){
    map<node*,node*> nodeToParent;
    node* targetNode = createParentMapping(root, target, nodeToParent);
    int ans = burnTree(targetNode, nodeToParent);
    return ans;
}
// MORRIS Traversal -Tc:O(n) & Sc:O(1)
// Preorder traversal without recursion and without stack  
void morrisTraversalPreorder(node* root)  {  
    while (root)  
    {  
        // If left child is null, print the current node data. Move to  
        // right child.  
        if (root->left == NULL)  
        {   
            cout<<root->data<<" ";  
            root = root->right;  
        }  
        else
        {  
            // Find inorder predecessor  
            node* current = root->left;  
            while (current->right && current->right != root)  
                current = current->right;  
  
            // If the right child of inorder predecessor already points to  
            // this node  
            if (current->right == root)  
            {  
                current->right = NULL;  
                root = root->right;  
            }  
  
            // If right child doesn't point to this node, then print this  
            // node and make right child point to this node  
            else
            {   
                cout<<root->data<<" ";  
                current->right = root;  
                root = root->left;  
            }  
        }  
    } 
}  
// Morris Traversal for PostOrder
void morrisTraversalPostorder(node* root)  {
    stack<int> s;  
    while (root)  
    {  
        // If right child is null, print the current node data. Move to  
        // left child.  
        if (root->right == NULL)  
        {  
            s.push(root->data);
            // cout<<root->data<<" ";  
            root = root->left;  
        }  
        else
        {  
            // Find postorder predecessor  
            node* current = root->right;  
            while (current->left && current->left != root)  
                current = current->left;  
  
            // If the left child of postorder predecessor already points to  
            // this node  
            if (current->left == root)  
            {  
                current->left = NULL;  
                root = root->left;  
            }  
  
            // If left child doesn't point to this node, then print this  
            // node and make left child point to this node  
            else
            {  
                s.push(root->data);
                // cout<<root->data<<" ";  
                current->left = root;  
                root = root->right;  
            }  
        }  
    }  
    while(!s.empty()){
    cout<<s.top()<<' ';
    s.pop();
    } 
}  
// Morris traversal for inorder
void MorrisTraversalInorder(node* root)
{
    node *current, *pre;
 
    if (root == NULL)
        return;
 
    current = root;
    while (current != NULL) {
 
        if (current->left == NULL) {
            cout << current->data << " ";
            current = current->right;
        }
        else {
 
            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL
                   && pre->right != current)
                pre = pre->right;
 
            /* Make current as the right child of its
               inorder predecessor */
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            }
 
            /* Revert the changes made in the 'if' part to
               restore the original tree i.e., fix the right
               child of predecessor */
            else {
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
            } /* End of if condition pre->right == NULL */
        } /* End of if condition current->left == NULL*/
    } /* End of while */
}
// Flatten a tree into Linked List
void Flatten(node* root){
    node* curr= root;
    while(curr != NULL){
        cout<<curr->data<<"->";
        if(curr->left){
            node* pred=curr->left;
            while(pred->right){
                pred=pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left= NULL;
        }
        curr = curr->right;
    }
    // return root;
}
int main(){
    node* root = NULL;
    // creating tree
    root = buildTree(root);
    //bloodline
    cout<<"sum of longest bloodline of tree: "<<sumOfLongRootToLeafPath(root)<<endl;
    //LOWEST COMMON ANCESTORS in a BT
    int n1=7,n2=17;
    cout<<"lowest common Ancestor of "<<n1<<" & "<<n2<<" is: "<<lca(root,n1,n2)->data<<endl;
    // No. of paths in tree have sum equal to k
    int k=11;
    cout<<"No. of paths in tree have sum equal to "<<k<<" is: "<<sumK(root,k)<<endl;
    //kth Ancestor
    k=2;
    n1=7;
    cout<<"kth Ancestor of node "<<n1<<" is: "<<kthAncestor(root,k,n1)<<endl;
    // max sum of non-adjacent nodes
    cout<<"max sum of non-adjacent nodes is: "<<getMaxSum(root)<<endl;
    // Construct tree from Inorder & Preorder
    int n=6;
    int inorder[n]={7,3,11,1,17,5};
    int preorder[n]={1,3,7,11,5,17};
    cout<<"postorder tree from inorder & preorder: ";
    buildtree(inorder,preorder,n);
     // Construct tree from Inorder & Postorder
    int inorder1[n]={7,3,11,1,17,5};
    int postorder[n]={7,11,3,17,5,1};
    cout<<endl<<"preorder tree from inorder & postorder: ";
    buildtree1(inorder1,postorder,n);
    // Burning Tree
    int target = 7;
    cout<<endl<<"Time taken for Burning Tree with target "<<target<<" is: "<<minTime(root,target)<<endl;
    // MORRIS Traversal
    cout<<"Morris preorder Traversal : ";
    morrisTraversalPreorder(root);
    cout<<endl<<"Morris postorder Traversal : ";
    morrisTraversalPostorder(root);
    cout<<endl<<"Morris Inorder Traversal : ";
    MorrisTraversalInorder(root);
    cout<<endl;
    // Flatten a tree into Linked List
    Flatten(root);
    return 0;
}
