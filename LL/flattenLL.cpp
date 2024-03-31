#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* right = NULL;
    node* down = NULL;
    node(int d){
        this->data = d;
        this->right = NULL;
        this->down = NULL;
    }
    ~node(){
        if(this->right != NULL) {
            delete right;
            right = NULL;
        }
        if(this->down != NULL) {
            delete down;
            down = NULL;
        }
    }
};
void insertatright(node* &rhead,node* &rtail,int d){
    node* temp = new node(d);
    if(rhead == NULL){
        rhead= temp;
        rtail = temp;
        return;
    }
    else{
        rtail->right = temp;
        rtail=temp;
    }
}
void insertatdown(node* &dhead,node* &dtail,int d){
    node* temp = new node(d);
    if(dhead == NULL){
        dhead = temp;
        dtail = temp;
        return;
    }
    else{
        dtail->down = temp;
        dtail=temp;
    }
}
void print(node* rhead){
    node* rtemp = rhead;
    node* dtemp = rtemp->down;
    while(rtemp!=NULL){
        cout<<rtemp->data;
        while(dtemp != NULL){
            cout<<"->"<<dtemp->data;
            dtemp = dtemp->down;
        }
        cout<<endl;
        cout<<"|"<<endl;
        rtemp = rtemp->right;
        dtemp = rtemp->down;
    }
    cout<<endl;
}
node* getmiddle(node* &head){
    if(head == NULL || head->right == NULL){
        return head;
    }
    node* slow = head;
    node* fast = head -> right;
    while(fast != NULL && fast -> right != NULL) {
        slow = slow -> right;
        fast = fast -> right -> right; 
    }
    return slow;
}
node* merge(node* &left, node* &right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }
    node* ans = new node(-1);
    node* temp = ans;
    while(left != NULL && right != NULL){
        if(left->data < right->data){
            temp->right = left;
            temp = left;
            left = left->right;
        }
        else{
            temp->right = right;
            temp = right;
            right = right->right;
        }
    }
    while(left != NULL){
        temp->right = left;
        temp = left;
        left = left->right;
    }
    while(right != NULL){
        temp->right = right;
        temp = right;
        right = right->right;        
    }
    ans = ans->right;
    return ans;
}
node* mergesort(node* &dhead){
    if(dhead == NULL || dhead->down == NULL){
        return dhead;
    }
    node* mid = getmiddle(dhead);
    node* left = dhead;
    node* right = mid->down;
    mid->down = NULL;
    left = mergesort(left);
    right = mergesort(right);
    node* result = merge(left,right);
    return result;
}
int main(){
    node* rhead = NULL;
    node* rtail = NULL;
    node* dhead = NULL;
    node* dtail = NULL;
    dhead = rtail;
    dtail = dhead;
    insertatright(rhead,rtail,2);
    insertatdown(dhead,dtail,3);
    insertatdown(dhead,dtail,4);
    insertatdown(dhead,dtail,1);
    insertatdown(dhead,dtail,5);
    dhead = rtail;
    dtail = dhead;
    insertatright(rhead,rtail,1);
    insertatdown(dhead,dtail,3);
    insertatdown(dhead,dtail,4);
    insertatdown(dhead,dtail,1);
    dhead = rtail;
    dtail = dhead;
    insertatright(rhead,rtail,6);
    insertatdown(dhead,dtail,3);
    insertatdown(dhead,dtail,4);
    dhead = rtail;
    dtail = dhead;
    insertatright(rhead,rtail,1);
    insertatdown(dhead,dtail,3);
    insertatdown(dhead,dtail,4);
    dhead = rtail;
    dtail = dhead;
    insertatright(rhead,rtail,0);
    insertatdown(dhead,dtail,2);
    dhead = rtail;
    dtail = dhead;
    insertatright(rhead,rtail,5);
    insertatdown(dhead,dtail,3);
    print(rhead);
    node* result = mergesort(dhead);
    print(result);
}