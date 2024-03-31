#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next=NULL;
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
node* addLL(node* head1,node* head2){
    int carry = 0;
    int sum = 0;
    int digit = 0;
    node* anshead = NULL;
    node* anstail = NULL;
    while(head1 != NULL && head2 != NULL){
        sum = carry + head1->data + head2->data;
        digit = sum%10;
        insertattail(anshead,anstail,digit);
        carry = sum/10;
        head1 = head1->next;
        head2 = head2->next;
    }
    while(head1 != NULL){
        sum = carry + head1->data;
        digit = sum%10;
        insertattail(anshead,anstail,digit);
        carry = sum/10;
        head1 = head1->next;
    }
    while(head2 != NULL){
        sum = carry + head2->data;
        digit = sum%10;
        insertattail(anshead,anstail,digit);
        carry = sum/10;
        head2 = head2->next;
    }
    while(carry != 0){
        carry = carry%10;
        insertattail(anshead,anstail,carry);
        carry = carry/10;
    }
    return anshead;
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
    node* head2 = NULL;
    node* tail2 = NULL;
    insertattail(head2,tail2,22);
    insertattail(head2,tail2,3);
    insertattail(head2,tail2,3);
    insertattail(head2,tail2,4);
    insertattail(head2,tail2,4);
    print(head2);
    head1 = ReverseLL(head1);
    head2 = ReverseLL(head2);
    node* ans = NULL;
    ans = addLL(head1,head2);
    ans = ReverseLL(ans);
    print(ans);
}