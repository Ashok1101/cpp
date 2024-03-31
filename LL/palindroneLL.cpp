#include<iostream>
#include<vector>
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
void insertattail(node* &tail,int d){
    node* temp = new node(d);
    tail->next = temp;
    tail=temp;
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
node* getmiddle(node* head){
    node* slow = head;
    node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
bool palindroneoptimize(node* head){   // O(n),O(1)
    if(head->next = NULL){
        return 1;
    }
    node* middle = getmiddle(head);
    node* temp = middle->next;
    node* head2 = ReverseLL(temp);
    node* head1 = head;
    while(head2 != NULL){
        if(head1->data != head2->data){
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return 1;
}
bool palindrone(node* head){   // O(n),O(n)
    vector<int> v;
    node* temp = head;
    while(temp != NULL){
        v.push_back(temp->data);
        temp= temp->next;
    }
    int s = 0;
    int e = v.size()-1;
    while(s<=e){
        if(v[s]==v[e]){
            s++;
            e--;
        }
        else{
            return 0;
        }
    }
    return 1;
}
int main(){
    node* node1 = new node(1);
    node* head = node1;
    node* tail = node1;
    insertattail(tail,2);
    insertattail(tail,3);
    insertattail(tail,3);
    insertattail(tail,2);
    insertattail(tail,1);
    print(head);
    if(palindrone(head)){
        cout<<"LL is in palindrone"<<endl;
    }
    else{
        cout<<"LL is not a palindrone"<<endl;
    }
    if(palindroneoptimize(head)){
        cout<<"LL is in palindrone"<<endl;
    }
    else{
        cout<<"LL is not a palindrone"<<endl;
    }
}