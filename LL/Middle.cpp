#include<iostream>
using namespace std;
class node{
    public: 
    int data;
    node* next;
    node(int d){
        data = d;
        next = NULL;
    }
    ~node(){
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};
int getlength(node* head){
    int len=0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}
void insertattail(node* &tail,int data){
    //new node create
    node* temp =new node(data);
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
node* getmiddle(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* slow = head;
    node* fast = head->next;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}
node* kreverse(node* head,int k){
    //base case
    if(head == NULL){
        return NULL;
    }
    node* next = NULL;
    node* prev = NULL;
    node* curr = head;
    int cnt=0;
    while(curr != NULL && cnt < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }
    if(next != NULL){
        head->next = kreverse(next,k);
    }
    return prev;
}
int main(){
    node* node1 = new node(1);
    node* head = node1;
    node* tail = node1;
    insertattail(tail,10);
    insertattail(tail,00);
    insertattail(tail,12);
    insertattail(tail,15);
    print(head);
    int len = getlength(head);
    int mid = len/2+1;
    if(len>0)
        cout<<"mid: "<<mid<<endl;
        node* temp = head;
        int cnt=1;
        while(cnt<mid){
            cnt++;
            temp = temp->next;
        }
        cout<<"middle element in LL is: "<<temp->data<<endl;
        temp = getmiddle(head);
        cout<<"middle by optimum sol. is: "<<temp->data<<endl;
        int k=2;
        temp = kreverse(head,k);
        print(temp);
}