#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Queue{
    int *arr;
    int qfront;
    int rear;
    int size=100;
    public: 
        Queue(int s=100){
            arr = new int[size];
            qfront=0;
            rear=0;
        }
        bool isEmpty(){
            if(qfront==rear==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        void enqueue(int data){
            if(rear==size){
                cout<<"Queue is Full"<<endl;
            }
            else{
                arr[rear]=data;
                rear++;
            }
        }
        int dequeue(){
            if(qfront==rear){
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
                return ans;    
            }
        }
        int front(){
            if(qfront==rear){
                return -1;
            }
            else{
                return arr[qfront];
            }
        }

};
int main(){
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Front: " << q.front() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Front: " << q.front() << endl;
    return 0;
}