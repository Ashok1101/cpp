#include<iostream>
#include<stack>
#include<queue>
#include<map>
using namespace std;

// reverse queue using stack
queue<int> reverse(queue<int> q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    return q;
}

// first -ve int in every window of size k
vector<int> neg(int *arr,int k,int n){
    deque<int>dq;
    vector<int> ans;
    //process 1st window
    for(int i=0;i<k;i++){
        if(arr[i]<0){
            dq.push_back(i);
        }
    }
    //store ans of 1st window
    if(dq.size()>0){
        ans.push_back(arr[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
    //process for remaining windows
    for(int i=k;i<n;i++){
        if(!dq.empty() && i-dq.front()>=k){
            dq.pop_front();
        }
        //addition
        if(arr[i]<0){
            dq.push_back(i);
        }
        //ans store
        if(dq.size() > 0){
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
}

// reverse 1st k element of queue 
queue<int> modifyQue(queue<int>q,int k){
    stack<int>s;
    int d = q.size()-k;
    while(k>0){
        s.push(q.front());
        q.pop();
        k--;
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    while(d>0){
        q.push(q.front());
        q.pop();
        d--;
    }
    return q;
}
// 1st non-repeating
string FirstNonRepeating(string A){
    map<char, int> m;
    string ans = "";
    queue<char> q;
    
    for(int i=0; i<A.length(); i++) {
        char ch = A[i];
        
        q.push(ch);
        m[ch]++;
        
        while(!q.empty()) {
            if(m[q.front()] > 1){
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}

//circular track
struct petrolPump
{
    int petrol;
    int distance;
};
int circulartrack(petrolPump p[],int n){
    int deficit = 0;
    int balance = 0;
    int start = 0;
    for(int i=0; i<n; i++) {
        balance += p[i].petrol - p[i].distance;
        if(balance < 0) {
            start = i+1;
            deficit += balance;
            balance = 0;
        }
    }
    if(balance + deficit >=0) 
        return start;
    return -1;
}

//NQueue in an array
class kQueue {
    public:
        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int freeSpot;
        int *next;
    public:
        kQueue(int n, int k) {
            this -> n = n;
            this -> k = k;
            front = new int[k];
            rear = new int[k];
            for(int i=0; i<k; i++) {
                front[i] = -1;
                rear[i] = -1;
            }
            next = new int[n];
            for(int i=0; i<n; i++) {
                next[i] = i+1;
            }
            next[n-1] = -1;
            arr = new int[n];
            freeSpot = 0;
        }    
        void enqueue(int data, int qn) {
            //overflow
            if( freeSpot == -1) {
                cout << "No Empty space is present" << endl;
                return;
            }
            //find first free index
            int index = freeSpot;
            //update freespot
            freeSpot = next[index];
            //check whther first element
            if(front[qn-1] == -1){
                front[qn-1] = index;
            }
            else{
                //link new element to the prev element
                next[rear[qn-1]] = index;
            }
            //update next
            next[index] = -1;
            //update rear
            rear[qn-1] = index;
            //push element
            arr[index] = data;
        }
        int dequeue(int qn) {
            //underflow 
            if(front[qn-1] == -1)
            {
                cout << "Queue UnderFlow " << endl;
                return -1;
            }
            //find index to pop
            int index = front[qn-1];
            //front ko aage badhao
            front[qn-1] = next[index];
            //freeSlots ko manage karo
            next[index] = freeSpot;
            freeSpot = index;
            return arr[index];
        }
};

// sum of max & min in k elements
int summaxmin(int *arr, int n, int k) {
    deque<int> maxi(k);
    deque<int> mini(k);
    //Addition of first k size window
    for(int i=0; i<k; i++) {
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();
        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;
    ans += arr[maxi.front()] + arr[mini.front()];
    //remaining windows ko process karlo
    for(int i=k; i<n; i++) {
        //next window
        //removal
        while(!maxi.empty() && i - maxi.front() >=k) {
            maxi.pop_front();
        }
        while(!mini.empty() && i - mini.front() >=k) {
            mini.pop_front();
        }
        //addition
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();
        maxi.push_back(i);
        mini.push_back(i);    
        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}

int main(){
    // reverse queue using stack
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q = reverse(q);
    while(!q.empty()){
        cout<<q.front()<<' ';
        q.pop();
    }cout<<endl;
    // first -ve int in every window of size k
    int arr[6]={-8,2,3,-6,10};
    int k=2;
    int n= sizeof(arr) / sizeof(arr[0]);
    vector<int> ar=neg(arr,k,n);
    for(int i:ar){
        cout<<i<<" ";
    }cout<<endl;

    // reverse 1st k element of queue 
    queue<int>q1; 
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    k=3;
    q1 = modifyQue(q1,k);
    while(!q1.empty()){
        cout<<q1.front()<<' ';
        q1.pop();
    }cout<<endl;
    // 1st non-repeating
    string A="aabcaa";
    cout<<FirstNonRepeating(A)<<endl;
    
    // circular track
    n = 4;
    int petrol[n]={4,6,7,4};
    int distance[n]={6,5,3,5};
    petrolPump p[n];
    for(int i=0;i<n;i++){
        p[i].petrol=petrol[i];
        p[i].distance=distance[i];
    }
    cout<<"starting index: "<<circulartrack(p,n)<<endl;
    // NQueue in an array
    kQueue q2(10, 3);
    q2.enqueue(10, 1);
    q2.enqueue(15,1);
    q2.enqueue(20, 2);
    q2.enqueue(25,1);
    cout << q2.dequeue(1) << endl;
    cout << q2.dequeue(2) << endl;
    cout << q2.dequeue(1) << endl;
    cout << q2.dequeue(1) << endl;
    cout << q2.dequeue(1) << endl;
    
    // sum of max & min in k elements
    int ar1[7]={2,5,-1,7,-3,-1,-2};
    n=sizeof(ar1)/sizeof(ar1[0]);
    cout<<summaxmin(ar1,n,4);
    return 0;
}