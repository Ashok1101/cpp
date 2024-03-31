#include<iostream>
using namespace std;
// Reverse LL
class node{
    public:
    int data;
    node* next;
    node(int d){
        this->data = d;
        this->next = NULL;
    }
};
node* ReverseLL(node* head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    node* prev = NULL;
    node* curr = head;
    node* forward = NULL;
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
void insertattail(node* &tail, int d){
    //new node create
    node* temp =new node(d);
    tail->next = temp;
    tail=temp;
}
void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}
// reverse recursively
node* reversell(node* &head,node* curr,node* prev){
    if(curr == NULL){
        head = prev;
        return head;
    }
    node* forward = curr->next;
    reversell(head,forward,curr);
    curr->next = prev;
}
int main(){
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    insertattail(tail,0);
    insertattail(tail,12);
    insertattail(tail,15);
    print(head);
    node* temp = ReverseLL(node1);   // O(n),O(1)
    print(temp);
    // reverse recursively
    node* curr = temp;
    node* prev = NULL;
    reversell(head,curr,prev);
    print(head);
}