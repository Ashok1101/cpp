#include <iostream>
// #include <bits/stdc++.h>  //used to include all header files 
#include<math.h>
#include<array> // for STL
#include<vector> // for STL
#include<deque> // for STL
#include<list> // STL
#include<stack> // STL
#include<queue> // STL
#include<set>  // STL
#include<map>  // STL
#include<algorithm> //STL
#include<string>
using namespace std;

int main()
{
    char ch='r'; //1byte
    int size=sizeof(ch);
    cout<<size<<endl;
    int a='a'; //typecast
    cout<<a<<endl;
    char c = 98;
    cout<<c<<endl;
    // int m=cin.get();
    // cout<<m; //returns ASCII value
    //patterns
    int n=4; // 4byte
    // cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<j;
            j++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl; 
    i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<n-j+1;
            j++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl; 
    i=1;
    int count=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<count<<" ";
            j++;
            count++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl; 
    i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<'*';
            j++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl; 
    i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<i;
            j++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl; 
    i=1;
    count=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<count;
            j++;
            count++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl; 
    i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<i+j-1;
            j++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl; 
    i=1;
    while(i<=n){
        int j=i;
        while(j>0){
            cout<<j;
            j--;
        }
        cout<<endl;
        i++;
    }
    cout<<endl; 
    i=1;
    while(i<=n){
        int j=1;
        while(j<=i){      //without using '0'
            cout<<i-j+1;
            j++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl; 
    i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            char ch='A'+i-1;
            cout<<ch;
            j++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl; 
    i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            char ch='A'+j-1;
            cout<<ch;
            j++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl; 
    i=1;
    ch='A';
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<ch;
            ch++;
            j++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl; 
    i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            char ch='A'+i+j-2;
            cout<<ch;
            j++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl; 
    i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            char ch='A'+i-1;
            cout<<ch;
            j++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl; 
    i=1;
    ch='A';
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<ch;
            ch++;
            j++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl; 
    i=1;
    while(i<=n){
        int j=1;
        char ch='A'+n-i;
        while(j<=i){
            cout<<ch;
            j++;
            ch++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl; 
    i=1;
    while(i<=n){
        int j=1;
        while(j<=n-i){     
            cout<<" ";
            j++;
        }
        while(j<=n){
            cout<<'*';
            j++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl; 
    i=1;
    while(i<=n){
        int j=1;
        while(j<=n-i+1){     
            cout<<"*";
            j++;
        } 
        cout<<endl;
        i++;
    }
    int arr[n=10]={1,2,3,4,5,5,5,5,6,6};
    int ans=0;
    for(i=0;i<n;i++){
            ans=ans^arr[i];
    }
    cout<<ans<<endl;
    // binary search
    // 1st and last position of element
    int start=0;
    int end=n-1;
    int mid=(start+end)/2;
    int key=5;
    while(start<=end){
        if(arr[mid]==key){
            cout<<key<<" is present at index "<<mid<<endl;
            int i=mid;
            while(arr[mid]==arr[i-1]){
                i--;
            }cout<<"leftmost occurence of value "<<key<<" is at "<<i<<endl;
            int left=i;
            i=mid;
            while(arr[mid]==arr[i+1]){
                i++;
            }cout<<"rightmost occurence of value "<<key<<" is at "<<i<<endl;
            cout<<"total occurence of "<<key<<" is: "<<i-left+1<<endl;
            break;
        }
        if(key>arr[mid]){
            start= mid+1;
        }
        else if(key<arr[mid]){
            end= mid-1;
        }
        mid=(start+end)/2;
    }
    if(start>end){
        cout<<key<<" is absent."<<endl;
    }
    // mountain/peak value
    int arrr[n=5]={1,3,7,2,0};
    start=0;
    end=n-1;
    mid=(start+end)/2;
    while(start<end){
        if(arrr[mid]<arrr[mid+1]){
            start=mid+1;
        }
        else{
            end=mid;
        }
        mid=(start+end)/2;
    }
    cout<<"peak value of array is "<<mid<<endl;
    // sorted rotated array search
    int ra[n=6]={4,5,6,1,2,3};
    int target= 6;
    // step 1: pivot element
    start=0;
    end=n-1;
    mid=(start+end)/2;
    while(start < end){
        if(ra[mid] >= ra[0]){
            start=mid+1;
        }
        else{
            end=mid;
        }
        mid=(start+end)/2;
    }
    int pivot =start; 
    cout<<"Pivot element is "<<ra[start]<<" at index "<<pivot<<endl;
    // step 2:
    if(ra[pivot] <=target && target<= ra[n-1]){
        start=pivot;
        end=n-1;
        mid=(start+end)/2;
    }
    else{
        start=0;
        end=pivot-1;
        mid=(start+end)/2;
    }
    // step 3:
    while(start<=end){
        if(ra[mid]>target){
            end=mid-1;
        }
        else if(ra[mid]<target){
            start=mid+1;
        }
        else if(ra[mid]==target){
            cout<<target<<" is found at index "<<mid<<endl;
            break;
        }
        else{
             cout<<target<<" is not found."<<endl;
        }
        mid=(start+end)/2;
    }
    // square root
    n=90;
    start=0;
    end=n;
    mid=(start+end)/2;
    while(start<=end){
        int sq=mid*mid;
        if(sq==n){
            ans=mid;
            break;
        }
        else if(sq<n){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=(start+end)/2;
    }
    cout<<"square root of "<<n<<" is "<<mid<<endl;
    // perfect sq root
    int precision=3; // till 3 digits
    double factor=1;
    double ans2 =mid;
    for(i=0;i<precision;i++){
        factor= factor/10;
        for(double j=ans;j*j<n;j=j+factor){
            ans2=j;
        }
    }
    cout<<"square root of "<<n<<" till 3 digits is "<<ans2<<endl;
    // allocate book
    // painters partition
    // aggresive cows prblm
    // selection sort
    int ab[n=6]={1,3,4,8,4,6};
    for(i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(ab[min]>ab[j]){
                min=j;
            }
        }
        swap(ab[i],ab[min]);
        cout<<ab[i]<<",";
    }
    cout<<endl;
    // bubble sort 
    int arrey[n=6]={3,6,4,8,7,1};
    for(int j=0;j<n-1;j++){
        for(i=0;i<n-j-1;i++){
            if(arrey[i]>arrey[i+1]){
                swap(arrey[i],arrey[i+1]);
            }
        }
    }
    for(i=0;i<n;i++){
        cout<<arrey[i]<<",";       
    }
    cout<<endl;
    // Insertion sort - adaptive,stable, time=O(n^2),space=O(1),best time=O(n)
    int eray[n=6]={3,6,3,8,7,1};
    for(i=1;i<n;i++){
        int temp= eray[i];
        int j=i-1;
        for(;j>=0;j--){
            if (eray[j]>temp){
                eray[j+1]=eray[j];
            }
            else{
                break;
            }
        }eray[j+1]=temp;
    }
    for(i=0;i<n;i++){
        cout<<eray[i]<<',';
    }cout<<endl;
    // STL
    // 1) array
    // #include<array>
    array<int,4> ay ={1,2,3,4};
    size =ay.size();
    for(i=0;i<size;i++){
        cout<<ay[i]<<",";
    }cout<<endl;
    cout<<"Element at 2nd Index-> "<<ay.at(2)<<endl;
    cout<<"Empty or not-> "<<ay.empty()<<endl; //'0'-> not empty
    cout<<"First Element-> "<<ay.front()<<endl;
    cout<<"Last Element-> "<<ay.back()<<endl;
    // 2) vector
    vector<int> v;
    cout<<"Capacity-> "<<v.capacity()<<endl; //capacity at start is 0
    v.push_back(1);
    cout<<"Capacity-> "<<v.capacity()<<endl; 
    v.push_back(2);
    cout<<"Capacity-> "<<v.capacity()<<endl;
    v.push_back(a);
    cout<<"Capacity-> "<<v.capacity()<<endl; // capacity don't increases by 1 it get's double
    cout<<"Size-> "<<v.size()<<endl;
    cout<<"Element at 2nd Index-> "<<v.at(2)<<endl;
    cout<<"First Element-> "<<v.front()<<endl;
    cout<<"Last Element-> "<<v.back()<<endl;
    cout<<"before pop"<<endl;
    for(int i:v){
        cout<<i<<" ";
    }cout<<endl;
    v.pop_back();
    cout<<"after pop"<<endl;
    for(int i:v){
        cout<<i<<" ";   
    }cout<<endl;
    cout<<"before clear size "<<v.size()<<endl;
    v.clear();
    cout<<"after clear size "<<v.size()<<endl;
    cout<<"Capacity remain same-> "<<v.capacity()<<endl;
    vector<int> A(5,1); //vector of len 5 n all values '1'
    for(int i:A){
        cout<<i<<" ";   
    }cout<<endl;
    vector<int> C(A); //to copy vector A in C
    for(int i:C){
        cout<<i<<" ";   
    }cout<<endl;
    // 3)Deque
    deque<int> d;
    d.push_back(1);
    d.push_front(2);
    d.push_back(3);
    d.pop_front();
    // d.pop_back();
    for(int i:d){
        cout<<i<<" ";   
    }cout<<endl;
    cout<<"First Element "<<d.at(1)<<endl;
    cout<<"Front "<<d.front()<<endl;
    cout<<"Back "<<d.back()<<endl;
    cout<<"empty or not "<<d.empty()<<endl;
    cout<<"Before erase "<<d.size()<<endl;
    d.erase(d.begin(),d.begin()+1);
    for(int i:d){
        cout<<i<<" ";   
    }cout<<endl;
    // 4) List
    list<int>l;
    l.push_back(2);
    l.push_front(1);
    l.erase(l.begin());
    for(int i:l){
        cout<<i<<" "; 
    }cout<<endl;
    // cout<<"First Element "<<l.at(1)<<endl; //not applicable
    // all other steps are applicable
    // 5) Stack
    stack<string> s;
    s.push("Arvind");
    s.push("Shamji");
    s.push("Patel");
    cout<<"Top Element "<<s.top()<<endl;
    s.pop();
    cout<<"Top Element "<<s.top()<<endl;
    // 6) Queue
    queue<string>q;
    q.push("Arvind");
    q.push("Shamji");
    q.push("Patel");
    cout<<"First Element "<<q.front()<<endl;
    q.pop();
    cout<<"First Element "<<q.front()<<endl;
    // 7) Priority queue
    // max heap
    priority_queue<int> maxi;
    // min heap
    priority_queue<int,vector<int> , greater<int> > mini;
    maxi.push(1);
    maxi.push(4);
    maxi.push(3);
    maxi.push(2);
    int len=maxi.size();
    for(int i=0;i<len;i++){
        cout<<maxi.top()<<" "; 
        maxi.pop();
    }cout<<endl;
    mini.push(1);
    mini.push(4);
    mini.push(3);
    mini.push(2);
    len=mini.size();
    for(int i=0;i<len;i++){
        cout<<mini.top()<<" "; 
        mini.pop();
    }cout<<endl;
    // 8)set
    set<int>se; //modification is not allowed, takes 1 value 1 time only even it occurs many times
    se.insert(5);
    se.insert(5);
    se.insert(1);
    se.insert(1);
    se.insert(2);
    se.insert(0);
    se.insert(0);
    se.insert(3);
    se.insert(3);
    se.erase(se.begin());
    cout<<se.count(5)<<endl;
    for(int i:se){
        cout<<i<<endl;
    }
    // 9) map
    map<int,string> m;
    m[1]="Arvind";
    m[2]="Shamji";
    m[5]="Patel";
    m.insert({3,"Verat"});
    cout<<m.count(2)<<endl;
    m.erase(5);
    for(auto i:m){
        cout<<i.first<<"->"<<i.second<<endl;
    }
    // 10)vector,algorithm
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(5);
    cout<<"Finding 5->"<<binary_search(v1.begin(),v1.end(),5)<<endl;
    cout<<"Finding 5 in lowerbound->"<<lower_bound(v1.begin(),v1.end(),5)-v1.begin()<<endl;
    cout<<"Finding 5 in upperbound->"<<upper_bound(v1.begin(),v1.end(),5)-v1.begin()<<endl;
    cout<<"max->"<<max(2,5)<<endl;
    cout<<"min->"<<min(2,5)<<endl;
    string abc="abcd";
    reverse(abc.begin(),abc.end());
    cout<<"string->"<<abc<<endl;
    rotate(v1.begin(),v1.begin()+1,v1.end());
    cout<<"after rotate-> ";
    for(int i:v1){
        cout<<i<<" ";
    }cout<<endl;
    // char array
    char ca[20];
    cout<<"Enter a string:"<<endl;
    // cin>>ca;
    // ca='Arvind Patel';
    int countt=0;
    for(i=0;ca[i]!='\0';i++){
        countt++;
    }
    cout<<"Length "<<count<<endl;
    // palindrone 
    string st="Gabbag";
    auto tolowercase=[](char ch){
        if(ch>='A' && ch<='Z'){
            ch=(ch-'A')+'a';
            return ch;
        }
        else{
            return ch;
        }
    };
    n=st.length();
    start=0;
    int e=n-1;
    while(start<=e){
        if(tolowercase(st[start]) != tolowercase(st[e])){
            cout<<"not palindrone!"<<endl;
            break;
        }
        else if(start==n/2-1){
            cout<<st<<" is a palindrone!!!"<<endl;
            break;
        }
        else{
            start++;
            end--;
        }
    }
    start=0;
    e=n-1;
    while(start<e){
        swap(st[start++],st[e--]);
        if(start==n/2-1){
            cout<<st<<" is a palindrone!"<<endl;
            break;
        }
    }
    cout<<st.at(2)<<endl;
    cout<<st.back()<<endl;
    st.insert(3,st);
    // st.clear();
    cout<<st.find('b');
    st.erase(st.find('b'),2);
    st.append("bb");
    cout<<st.compare(st)<<endl;
    swap(st,st);
    for(i=0;st[i]!='\0';i++){
        cout<<st[i];
    }cout<<endl;
    // 2d array
    // int ar[][3]={1,2,3,4,5,6,7,8,9}; //no. of col is must 
    int ar[][3]={{1,2,3},{4,5,6},{7,8,9}};
   // row wise
    for(int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            cout<<ar[i][j]<<" ";
        }cout<<endl;       
    }
    // col wise
    for(int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            cout<<ar[j][i]<<" ";
        }cout<<endl;       
    }
    // to find element
    int tar=5;
    count=0;
    for(int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if(ar[i][j]==tar){
                cout<<tar<<" found at: "<<i<<","<<j<<endl;
                count++;
                break;
            }
        }      
    }
    if(count==0){
        cout<<"not found"<<endl;
    }
    // row wise sum
    int sum=0;
    for(int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            sum+=ar[i][j];
        }cout<<"sum of row "<<i+1<<" is "<<sum<<endl; 
        sum=0;      
    }    
    // wavy col wise
    for(int i=0;i<3;i++){
        if(i%2==0){
            for (int j=0;j<3;j++){
                cout<<ar[j][i]<<" ";
            }
        }
        else{
            for (int j=2;j>=0;j--){
                cout<<ar[j][i]<<" ";
            }
        }    
    }cout<<endl;
    // spiral traverse
    // vector<vector<int>>v2;
    // v2={{1,2,3},{4,5,6},{7,8,9}};
    int v2[][3]={{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans1;
    int row = sizeof(v2)/sizeof(v2[0]);
    int col = sizeof(v2[0])/sizeof(v2[0][0]);
    count=0;
    int total=row*col;

    int startingrow =0;
    int startingcol =0;
    int endingrow =row-1;
    int endingcol =col-1;

    while(count<total){
        //print starting row
        for(int i=startingcol;count<total && i<=endingcol;i++){
            ans1.push_back(v2[startingrow][i]);
            count++;
        }startingrow++;

        //print ending col
        for(int i=startingrow;count<total && i<=endingrow;i++){
            ans1.push_back(v2[i][endingcol]);
            count++;
        }endingcol--;

        //print ending row
        for(int i=endingcol;count<total && i<=startingcol;i--){
            ans1.push_back(v2[endingrow][i]);
            count++;
        }endingrow--;

        //print starting col
        for(int i=endingrow;count<total && i<=startingrow;i--){
            ans1.push_back(v2[i][startingcol]);
            count++;
        }startingcol++;
    }
    cout<<"spiral matrix: "<<endl;
    for(int i:ans1){
        cout<<i<<" ";
    }cout<<endl;
    //Prime no
    n=3;
    count=0;
    if(n==0 || n==1){
        cout<<n<<" is not prime."<<endl;
    }
    for(int i=2;i<n;i++){
        if(n%i==0){
            cout<<n<<" is not prime."<<endl;
            count++;
            break;
        }
    }
    if(count==0){
        cout<<n<<" is a prime."<<endl;
    }
    // count prime nos
    count=0;
    int ct=0;
    if(n<=1){
        count=0;
    }
    for(int i=2;i<n;i++){
        for(int j=2;j<i;j++){
            if(i%j==0){
                ct++;
                break;
            }
        }
        if(ct==0){
            count++;
            // cout<<count;
        }
        ct=0;
    }
    cout<<"count of prime nos: "<<count<<endl;
    // using function
    auto isprime=[](int n){ // to define fun inside main fun
        if(n==0 || n==1){
            return false;
        }
        for(int i=2;i<n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;       
    };
    count=0;
    // n=50000000;
    for(i=2;i<n;i++){
        if(isprime(i)){
            count++;
        }
    }
    cout<<"count of prime nos: "<<count<<endl;
    // Sieve of eratothenes       //time complexity:n*log(log n)
    count=0;
    vector<bool>prime(n,true);
    n=3;
    prime[0]=prime[1]=0;
    for(i=2;i<n;i++){
        if(prime[i]){
            count++;
            for(int j=i*2;j<n;j+=i){
                prime[j]=0;
            }
        }
    }
    cout<<"count of prime nos: "<<count<<endl;
    // GCD/HCF [Euclid]
    auto gcd=[](int a,int b){
        while(a!=0 && b!=0){
            if(a>b){
                // a-=b;
                a%=b;
            }
            else{
                // b-=a;
                b%=a;
            }
        }
        if(a==0){
            return b;
        }
        return a;
    };
    int hcf=gcd(12,39);
    cout<<"gcd is "<<hcf<<endl;
    // fast exponential
    int res =1;
    int x=10;
    n=8;
    while(n>0){
        if(n&1){ //to check odd   
            res=res*x;
        }
        x=x*x;
        n=n>>1;
    }
    cout<<res<<endl;
    // reverse array
    int arr1[n=6]={2,4,3,5,9,6};
    for(i=0;i<n/2;i++){
        swap(arr1[i],arr1[n-i-1]);
        cout<<arr1[i]<<",";
    }cout<<endl;
    // merge sorted array
    int arr2[]={1,3,5,7,8,9};
    int arr3[]={2,4,10};
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    int n3=sizeof(arr3)/sizeof(arr3[0]);
    int arr4[n2+n3];
    i=0;
    int j=0,k=0;
    while(i<n2 && j<n3){
        if(arr2[i]<arr3[j]){
            arr4[k]=arr2[i++];
        }
        else{
            arr4[k]=arr3[j++];
        }
        cout<<arr4[k++]<<',';
    }
    while(i<n2){
        arr4[k]=arr2[i++];
        cout<<arr4[k++]<<",";
    }
    while(j<n3){
        arr4[k]=arr3[j++];
        cout<<arr4[k++]<<",";
    }cout<<endl;
    // rotate array
    k=2; //rotate each element of aar4[] by 2 position to right
    n=n2+n3;
    int arr5[n];
    for(i=0;i<n;i++){
        arr5[(i+k)%n]=arr4[i];
    }
    for(i=0;i<n;i++){
        cout<<arr5[i]<<',';
    }cout<<endl;
    //sum of arrays
    int carry=0;
    i=n2-1;
    j=n3-1;
    if(i>j){
        n=i+1;
    }
    else{
        n=j+1;
    }
    int arr6[n];
    while(i>=0 && j>=0){
        arr6[n--]=(arr2[i]+arr3[j]+carry)%10;
        carry=(arr2[i--]+arr3[j--]+carry)/10;
    }
    while(i>=0){
        arr6[n--]=(arr2[i]+carry)%10;
        carry=(arr2[i--]+carry)/10;
    }
    while(j>=0){
        arr6[n--]=(arr3[j]+carry)%10;
        carry=(arr3[j--]+carry)/10;
    } 
    arr6[0]=carry;
    k=sizeof(arr6)/sizeof(arr6[0]);
    for(i=0;i<=k;i++){
        cout<<arr6[i]<<',';
    }cout<<endl;
    return 0;
}