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
node *solve(node *first, node *second){
    // if only one element is present in first list
    if (first->next == NULL)
    {
    first->next = second;
    return first;
    }

    node* curr1 = first;
    node* next1 = curr1->next;
    node* curr2 = second;
    node* next2 = curr2->next;
    while (next1 != NULL && curr2 != NULL){
        if((curr2->data >= curr1->data) && (curr2->data <= next1->data)){
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            // update pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            // curr1 and next1 ko aage badhana padega
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}
node *sortTwoLL(node *first, node *second){
    if (first == NULL)
    return second;

    if (second == NULL)
        return first;

    if (first->data <= second->data){
        return solve(first, second);
    }
    else{
        return solve(second, first);
    }
}
int main(){
    node* node1 = new node(2);
    node* head1 = node1;
    node* tail1 = node1;
    insertattail(tail1,2);
    insertattail(tail1,3);
    insertattail(tail1,3);
    insertattail(tail1,4);
    insertattail(tail1,5);
    print(head1);
    node* node2 = new node(1);
    node* head2 = node2;
    node* tail2 = node2;
    insertattail(tail2,2);
    insertattail(tail2,3);
    insertattail(tail2,3);
    insertattail(tail2,4);
    insertattail(tail2,4);
    print(head2);
    node* head = sortTwoLL(head1,head2); 
    print(head);
}