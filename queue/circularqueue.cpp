#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class CircularQueue{
    int *arr;
    int qfront;
    int rear;
    int size=100;
    public: 
        CircularQueue(int s=100){
            arr = new int[size];
            qfront=0;
            rear=0;
        }
        bool isEmpty(){
            if(qfront==0 && rear==0){
                return true;
            }
            else{
                return false;
            }
        }
        void enqueue(int data){
            if((rear==size && qfront==0) || (rear==qfront && qfront!=0)){
                cout<<"Queue is Full"<<endl;
            }
            else if(rear==size){
                rear=0;
                arr[rear]=data;
                rear++;
            }
            else{
                arr[rear]=data;
                rear++;
            }
            cout<<arr[rear-1]<<endl;
        }
        int dequeue(){
            if(qfront==0 && rear==0){
                return -1;
            }
            else{
                int ans= arr[qfront];
                arr[qfront]=-1;
                qfront++;
                if(qfront==rear){
                    qfront=0;
                    rear=0;
                }
                else if(qfront==size){
                    qfront=0;
                }
                return ans;    
            }
        }
        int front(){
            if(qfront==0 && rear==0){
                return -1;
            }
            else{
                return arr[qfront];
            }
        }

};
int main(){
    CircularQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << "Front: " << q.front() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Front: " << q.front() << endl;
    return 0;
}