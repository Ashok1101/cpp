#include<iostream>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// delete middle element
void delmiddle(stack<int>&s,int cnt, int size){
    if(cnt == size/2){
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    delmiddle(s, cnt+1, size);
    s.push(temp);
}
// valid parenthesis
bool parenthesis(string s){
    stack<char> s2;
    for(int i=0;i<s.length();i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            s2.push(s[i]);
        }
        else{
            if(!s2.empty()){
                if((s[i] == ')' && s2.top() == '(') ||
                   (s[i] == '}' && s2.top() == '{') ||
                   (s[i] == ']' && s2.top() == '[')){
                    s2.pop();
                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
    }
        if(s2.empty()){
            return 1;
        }
        else{ 
            return 0;
        }
}
void insertatbottom(stack<int> &s, int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int temp = s.top();
    s.pop();
    insertatbottom(s, val);
    s.push(temp);
}
void reverse(stack<int> &s){
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    reverse(s);
    insertatbottom(s, temp);
}
void sortinsert(stack<int> &s, int num){
    if(s.empty() || s.top() < num){
        s.push(num);
        return;
    }
    int temp = s.top();
    s.pop();
    sortinsert(s,num);
    s.push(temp);
}
void sort(stack<int> &s){
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    sort(s);
    sortinsert(s, temp);
}
bool redundant(string &s){
    stack<char> s2;
    for(int i=0;i<s.length();i++){
        if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*'){
            s2.push(s[i]);
        }
        else{
            if(s[i] == ')'){
                bool isredundant = true;
                while(s2.top() != '('){
                    char top = s2.top();
                    if(top == '+' || top == '-' ||  top == '*' || top == '/'){
                        isredundant = false;
                    }
                    s2.pop();
                }
                if(isredundant == true){
                    return true;
                }
                s2.pop();
            }
        }
    }
    return false;
}
int mincost(string &s){
    //odd condition
    if(s.length()%2 == 1){
        return -1;
    }
    stack<char> s1;
    for(int i=0;i<s.length();i++){
        if(s[i] == '{'){
            s1.push(s[i]);
        }
        else{
            if(!s1.empty() && s1.top() == '{'){
                s1.pop();
            }
            else{
                s1.push(s[i]);
            }
        }
    }
    // stack contain invalid expression
    int a=0, b=0;
    while(!s1.empty()){
        if(s1.top() == '{'){
            b++;
        }
        else{
            a++;
        }
        s1.pop();
    }
    int ans =(a+b)/2 + (b+1)/2;
    return ans;
}
//next smaller element
vector<int> nextsmallerelement(vector<int> &v,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        int curr = v[i];
        while(s.top()>=curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
//prev smaller element
vector<int> prevsmallerelement(vector<int> &v,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int curr = v[i];
        while(s.top()>=curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
// largest rectangle area
int largestrectanglearea(vector<int>v){
    int n = v.size();
    vector<int> next(n);
    next = nextsmallerelement(v,n);
    vector<int> prev(n);
    prev = prevsmallerelement(v,n);
    int area= INT_MIN;
    for(int i=0;i<n;i++){
        int l = v[i];
        if(next[i]==-1){
            next[i]=n;
        }
        int b = next[i]-prev[i]-1;
        int newarea = l*b;
        area = max(area,newarea);
    }
    return area;
}
// celebrity problem
bool knows(vector<vector<int>> &m, int a, int b){
    if(m[a][b]==1){
        return true;
    }
    return false;
}
int celebrity(vector<vector<int>>m, int n){
    stack<int> s;
    //push all elements
    for(int i=0;i<n;i++){
        s.push(i);
    }
    // get 2 elements and compare them
    while(s.size()>1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(knows(m,a,b)){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int ans = s.top();
    // single element is potential celeb...so verify it 
    // row check
    bool rowcheck = false;
    int zerocount = 0;
    for(int i=0;i<n;i++){
        if(m[ans][i]==0){
            zerocount++;
        }
    }
    if(zerocount == n){
        rowcheck = true;
    }
    // col check
    bool colcheck = false;
    int onecount = 0;
    for(int i=0;i<n;i++){
        if(m[i][ans]==1){
            onecount++;
        }
    }
    if(onecount == n-1){
        colcheck = true;
    }
    if(rowcheck && colcheck){
        return ans;
    }
    else{
        return -1;
    } 
}
// max rectangle in binary matrix formed by all 1's
int maxarea(vector<vector<int>> &M,int m,int n){
    // compute area for first row 
    int area = largestrectanglearea(M[0]);
    //for remaining rows
    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            //row update: by adding prev row's value
            if(M[i][j] != 0){
                M[i][j] = M[i][j] + M[i-1][j];
            }
            else{
                M[i][j] = 0;
            }
        }
        //entire row is updated now
        area = max(area, largestrectanglearea(M[i]));
    }
    return area;
}
// Nstack in a array
class NStack {
private:
    int *arr;
    int *top;
    int *next;
    int n, s;
    int freespot;
// Initialize your data structure.
public:
    NStack(int N, int S) {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        // top initialize
        for (int i = 0; i < n; i++) {
            top[i] = -1;
        }
        // next initialize
        for (int i = 0; i < s - 1; i++) {
            next[i] = i + 1;
        }
        // update last index value to -1
        next[s - 1] = -1;
        // initialize freespot
        freespot = 0;
        cout<<push(1, 2)<<endl;
        cout<<pop(2)<<endl;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m) {
        // check for overflow
        if (freespot == -1) {
            return false;
        }
        // find index
        int index = freespot;
        // insert element into array
        arr[index] = x;
        // update freespot
        freespot = next[index];
        // update next;
        next[index] = top[m - 1];
        // update top
        top[m - 1] = index;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m) {
        // check underflow condition
        if (top[m - 1] == -1) {
            return -1;
        }
        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};
// special stack - getmin() in tc & sc of O(1)
class SpecialStack {
    // Define the data members.
	stack<int> s;
    int mini;
    public:
    void push(int data) {
        //for first element
        if(s.empty()) {
            s.push(data);
            mini = data;
        }
        else
        {
         	if(data < mini) {
                s.push(2*data - mini);
                mini = data;
            }   
            else{
                s.push(data);
            }
        }
    }
    int pop() {
        if(s.empty()){
            return -1;
        }     
        int curr = s.top();
        s.pop();
        if(curr > mini) {
            return curr;
        }
        else{
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }
    int top() {
        if(s.empty())
            return -1;
        int curr = s.top();
        if(curr < mini) {
            return mini;
        }
        else{
            return curr;
        }
    }
    bool isEmpty() {
        return s.empty();
    }
    int getMin() {
        if(s.empty())
            return -1; 
        return mini;
    }  
};
int main(){
    //reverse string using stack
    string st = "arvind patel";
    stack<char> s;
    for(int i=0;i<st.length();i++){
        s.push(st[i]);
    }
    string ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    cout<<"reverse of '"<<st<<"' is: "<<ans<<endl;

    // delete middle element
    stack<int>s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    int count =0;
    delmiddle(s1, count, s1.size());
    while(!s1.empty()){
    cout<<s1.top()<<' ';
    s1.pop();
    }
    cout<<"\n";
    // parenthesis check
    string st1 = "{}([()])[]";
    if(parenthesis(st1)){
        cout<<st1<<" is a valid parenthesis"<<endl;
    }
    else{
        cout<<st1<<" is not a valid parenthesis"<<endl;
    }
    // insert at bottom
    int val= 2;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    insertatbottom(s1, val);
    while(!s1.empty()){
    cout<<s1.top()<<' ';
    s1.pop();
    }
    cout<<"\n";
    //reverse stack
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);    
    reverse(s1);
    while(!s1.empty()){
    cout<<s1.top()<<' ';
    s1.pop();
    }
    cout<<"\n";
    // sort stack
    s1.push(-2);
    s1.push(4);
    s1.push(-3);
    s1.push(1);
    sort(s1);
    while(!s1.empty()){
    cout<<s1.top()<<' ';
    s1.pop();
    }
    cout<<"\n";
    // redundant bracket
    string str= "((a+b)*c)";
    if(redundant(str))
        cout<<str<<" is redundant"<<endl;
    else cout<<str<<" is not redundant"<<endl; 
    str = "{{{}";
    cout<<"min cost to make str valid: "<<mincost(str)<<endl;
    // next smaller element
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);
    int n = v.size();
    for(int i:nextsmallerelement(v,n)){
        cout<<i<<" ";
    }cout<<endl;
    // prev smaller element
    for(int i:prevsmallerelement(v,n)){
        cout<<i<<" ";
    }cout<<endl;
    // largest Rectangle Area
    cout<<"largest rectangle area is "<<largestrectanglearea(v)<<endl;
    // celebrity problem 
    vector<vector<int>> m;
    m= {{0,1,0},
        {0,0,0},
        {0,1,0}};
    n = m[0].size(); // to know no. of rows in matrix
    // m.size() - to know no. of cols in matrix
    cout<<celebrity(m,n)<<" is the celebrity"<<endl;
    // max rectangle in binary matrix formed by all 1's
    vector<vector<int>> M;
    M = {{0,1,1,0},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,0,0}};
    int r=M[0].size();
    int c=M.size();
    cout<<"max area formed by rect of all 1's is "<<maxarea(M,r,c)<<endl;
    // Nstack in a array
    int N=5; //no. of stacks
    int S = 6; //size of array
    NStack nStack(N,S);
    // special stack - getmin() in tc & sc of O(1)
    SpecialStack specialstack;
     // Function calls
    specialstack.push(5);
    specialstack.push(3);
    cout<<specialstack.getMin();
    specialstack.push(8);
    specialstack.push(2);
    cout<<specialstack.getMin();
    specialstack.pop();
    specialstack.push(4);
    cout<<specialstack.getMin();
    specialstack.pop();
    specialstack.top();
    cout<<specialstack.getMin();
    return 0;
}