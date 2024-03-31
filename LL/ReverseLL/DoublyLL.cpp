#include<iostream>
using namespace std;
// Reverse DoublyLL
class node{
    public: 
    int data;
    node* next;
    node* prev;
    node(int d){
        data = d;
        prev = NULL;
        next = NULL;
    }
    ~node(){
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
    }
};
void ReverseDLL(node* &head){
    if(head == NULL || head->next == NULL){
        head=head->prev;
    }
    // node* next = NULL;
    node* curr = head;
    // node* prev = NULL;
    node* forward = NULL;
    while(curr != NULL){
        forward = curr->prev;
        curr->prev = curr->next;
        curr->next = forward;  
        curr = curr->prev;  
    }
    head = forward->prev;
    // return head;
}
void insertAtTail(node* &tail,node* &head, int d){
    if(tail == NULL) {
        node* temp = new node(d);
        tail = temp;
        head = temp;
    }
    else{
        node* temp = new node(d);
        tail -> next  = temp;
        temp -> prev = tail;
        tail = temp;
    }

}
void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    insertAtTail(tail,head, 11);
    insertAtTail(tail,head, 13);
    insertAtTail(tail,head, 8);
    insertAtTail(tail,head, 25);
    print(head);
    ReverseDLL(head);   // O(n),O(1)
    print(head);
}