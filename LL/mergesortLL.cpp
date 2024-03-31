#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next = NULL;
    node(int d){
        this->data = d;
        this->next = NULL;
    }
    ~node(){
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
    }
};
void insertattail(node* &head,node* &tail,int d){
    node* temp = new node(d);
    if(head == NULL){
        head= temp;
        tail = temp;
        return;
    }
    else{
        tail->next = temp;
        tail=temp;
    }
}
void print(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}
node* getmiddle(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* slow = head;
    node* fast = head -> next;
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next; 
    }
    return slow;
}
node* merge(node* left, node* right){
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
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    while(left != NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while(right != NULL){
        temp->next = right;
        temp = right;
        right = right->next;        
    }
    ans = ans->next;
    return ans;
}
node* mergesort(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* mid = getmiddle(head);
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;
    left = mergesort(left);
    right = mergesort(right);
    node* result = merge(left,right);
    return result;
}
int main(){
    node* head = NULL;
    node* tail = NULL;
    insertattail(head,tail,2);
    insertattail(head,tail,1);
    insertattail(head,tail,6);
    insertattail(head,tail,1);
    insertattail(head,tail,0);
    insertattail(head,tail,5);
    print(head);
    node* result = mergesort(head);
    print(result);
}