#include<iostream>
#include<vector>
using namespace std;
// Recursion

// Fibonacci series
int fibo(int n){
    // base case
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    // recursive relation/call
    return fibo(n-1) + fibo(n-2);
}

// Climb stairs by 1 or 2 steps at a time
int stairs(int n){
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    int ans = stairs(n-1) + stairs(n-2);
    return ans;
}
// Say digits
string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
void saydigits(int n){
    // base case
    if(n==0){
        return;
    } 
    // processing
    int r = n%10;
    n=n/10;
    // recursive call
    saydigits(n);
    cout<<arr[r]<<" ";
}
// is array Sorted or not
bool issorted(int arr[],int size){
    if(size==0 || size==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        return issorted(arr+1,size-1); // don't use '--' or '++' operator in return statement 
    }
}
// sum
int sum(int arr[],int size){
    if(size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    return arr[0] + sum(arr+1,size-1);
}
// linear search
int count=0;
void linear(int arr[],int size,int key){
    if(size==0 && count==0){
        cout<<key<<" is not present in array"<<endl;
        return;
    }
    if(arr[0]==key){
        count++;
        cout<<key<<" is present in array "<<endl;
    }
    else{
        linear(arr+1,size-1,key);
    }
}
// binary search
void binary(int arr[],int s,int e,int key){
    int m=(s+e)/2;
    if(s>e){
        cout<<key<<" is not present in array"<<endl;
        return;
    }
    if(arr[m]==key){
        cout<<key<<" is present in array at index "<<m<<endl;
        return;
    }
    else if(arr[m]>key){
        e=m-1;
        binary(arr,s,e,key);
    }
    else{
        s=m+1;
        binary(arr,s,e,key);
    }
}
// reverse string
void reverse(string& s,int i,int l){
    if(i>=l){
        return;
    }
    swap(s[i++],s[l--]);
    reverse(s,i,l);
}
// palindrone
void palindrone(string s,int i,int j){
    // pre-processing
    if(s[i]>='A' && s[i]<='Z'){
        s[i]=(s[i]-'A')+'a';
    }
    //base case
    if(s[i]!=s[j]){
        cout<<s<<" is not palindrone"<<endl;
        return;
    }
    if(i>=j){
        cout<<s<<" is a palindrone"<<endl;
        return;
    }
    // processing
    i++;
    j--;
    // recursive case
    palindrone(s,i,j);
}
// a power b : (a^b)
double power(double a,int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    if(b%2 == 1){
        return a*power(a,b/2)*power(a,b/2);
    }
    else{
        return power(a,b/2)*power(a,b/2);
    }
}
// bubble sort 
void bubble(int*ar,int l){
    if(l==0 || l==1){
        return;
    }
    for(int j=0;j<l;j++){
        if(ar[j]>ar[j+1]){
            swap(ar[j],ar[j+1]);
        }
    }
    bubble(ar,l-1);
}
// mergesort
void merge(int *ra,int s,int e){
    int mid=(s+e)/2;
    int l1=mid-s+1;
    int l2=e-mid;
    int *first = new int[l1];
    int *second = new int[l2];
    int k=s;
    for(int i=0;i<l1;i++){
        first[i] = ra[k++];
    }
    k=mid+1;
    for(int i=0;i<l1;i++){
        second[i] = ra[k++];
    }
    // merge 2 sorted arrays
    int index1 =0;
    int index2 =0;
    k=s;
    while(index1 < l1 && index2 < l2){
        if(first[index1] < second[index2]){
            ra[k++] = first[index1++];
        }
        else{
             ra[k++] = second[index2++];
        }
    }
    while(index1 < l1){
        ra[k++] = first[index1++];
    }
    while(index2 < l2){
        ra[k++] = second[index2++];
    }
    delete[]first;
    delete[]second;
}
void mergesort(int *ra,int s,int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    mergesort(ra,s,mid); // left part
    mergesort(ra,mid+1,e); // right part
    merge(ra,s,e);
}
//quick sort
int partition(int *arr,int s,int e){
    int pivot=arr[s];
    int count =0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            count++;
        }
    }
    int pivotindex = s+count;
    swap(arr[pivotindex],arr[s]);
    int i=s, j=e;
    while(i<=pivotindex && j>=pivotindex){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i<=pivotindex && j>=pivotindex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotindex;
}
void quick(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    int p=partition(arr,s,e);
    quick(arr,s,p-1);
    quick(arr,p+1,e);
}
int main(){
    int n=10;
    cout<<fibo(n)<<endl;
    cout<<stairs(n)<<endl;
    saydigits(n);
    cout<<endl;
    int arr[5]={2,3,4,50,51};
    int size=sizeof(arr)/sizeof(arr[0]);
    if(issorted(arr,size)){
        cout<<"array is sorted"<<endl; 
    }
    else{
        cout<<"array is not sorted"<<endl; 
    }
    cout<<sum(arr,size)<<endl;
    int key=50;
    linear(arr,size,key);
    if(issorted(arr,size)){
        int s=0;
        int e=size;
        binary(arr,s,e,key);
    }
    // recursion with string

    // reverse the string
    string s="abcdefg";
    int i=0;
    int l=s.length();
    reverse(s,i,l-1);
    cout<<s<<endl;
    // palindrone
    string st="Bababab";
    i=0;
    l=st.length();
    palindrone(st,i,l-1);
    // a^b : a power b
    double a=1.2;
    int b=4;
    cout<<power(a,b)<<endl;
    // bubble sort
    int ar[6]={3,5,1,3,5,2};
    l=sizeof(ar)/sizeof(ar[0]);
    bubble(ar,l-1);
    for(i=0;i<l;i++){
        cout<<ar[i]<<',';
    }cout<<endl;
    // selection sort 
    // insertion sort
    // merge sort
    int ra[9]={2,4,3,5,7,5,9,0,8};
    n=9;
    mergesort(ra,0,n-1); // tc - O(nlogn)
    for(i=0;i<n;i++){
        cout<<ra[i]<<',';
    }cout<<endl; 
    // quick sort 
    int err[5]={1,5,2,6,7};
    n=5;
    quick(err,0,n-1);   //tc - O(nlogn) 
    for(i=0;i<n;i++){
        cout<<err[i]<<',';
    }cout<<endl;    
    return 0;
}