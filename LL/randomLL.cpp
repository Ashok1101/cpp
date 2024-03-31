#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next=NULL;
    node* random = NULL;
    node(int d){
        this->data = d;
        this->next = NULL;
        this->random = NULL;
    }
    ~node(){
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        if(this->random != NULL){
            delete random;
            random = NULL;
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
void printrandom(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->random;
    }
    cout<<endl;
}
int main(){
    node* head1 = NULL;
    node* tail1 = NULL;
    insertattail(head1,tail1,2);
    insertattail(head1,tail1,3);
    insertattail(head1,tail1,3);
    insertattail(head1,tail1,4);
    insertattail(head1,tail1,5);
    print(head1);
    node* temp = head1;
    temp->random = temp->next->next;
    temp= temp->next;
    temp->random = head1;
    temp = temp->next;
    temp->random = temp->next->next;
    temp= temp->next;  
    temp->random = head1->next;
    temp = temp->next;
    printrandom(head1);
}