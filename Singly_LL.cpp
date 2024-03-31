#include<iostream>
using namespace std;

class node{
    public: 
    int data;
    node* next;
    // constructor
    node(int data){
        this->data = data;
        this->next = NULL;
    }
    //destructor
    ~node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};
void insertathead(node* &head, int d){
    // new node create
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}
void insertattail(node* &tail, int d){
    //new node create
    node* temp =new node(d);
    tail->next = temp;
    tail=temp;
}
void insertatposition(node* &head,node* &tail,int position,int d){
    //insert at start
    if(position==1){
        insertathead(head,d);
        return;
    }
    node* temp = head;
    int count =1;
    while(count<position-1){
        temp = temp->next;
        count++;
    }
    //insert at last position
    if(temp->next == NULL){
        insertattail(tail,d);
        return;
    }
    //creating a node for d
    node*nodetoinsert = new node(d);
    nodetoinsert -> next = temp -> next;
    temp->next = nodetoinsert;
}
void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void deletenode(int position, node* &head){
    if(position ==1){
        node* temp = head;
        head = head->next;
        //free memory
        temp->next = NULL;
        delete temp;
    }
    else{
        //deleting any middle or last
        node* curr = head;
        node* prev = NULL;
        int count =1;
        while(count <= position){
            prev = curr;
            curr= curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main(){
    node* node1 = new node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    // head pointed to node1
    node* head = node1;
    print(head);
    insertathead(head,11);
    print(head);
    node* tail = node1;
    insertattail(tail,12);
    print(head);
    insertattail(tail,15);
    print(head);
    insertatposition(head,tail,4,13);
    print(head);
    insertatposition(head,tail,1,8);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    deletenode(1,head);
    print(head);
    return 0;
}