#include<iostream>
#include<string>
using namespace std;
int main(){
    int m=0;
    int *n=&m;
    cout<<*n<<"=="<<m<<endl;
    cout<<*n<<"=="<<++m<<endl;
    cout<<++*n<<"!="<<++m<<endl;
    cout<<sizeof(m)<<','<<sizeof(n)<<endl;
    int *p=0;         // null pointer
    p=n;
    cout<<*p<<endl;
    int *q=n;          //copying a pointer 
    cout<<*q<<endl;

    // pointers in array

    int arr[10]={1,3,5,6};
    cout<<"address of 1st element: "<<arr<<endl;
    cout<<"address of 1st element: "<<&arr[0]<<endl;
    cout<<"value at 1st element: "<<*arr<<"="<<arr[0]<<endl;
    int i=2;
    cout<<"value at index: "<<*(arr+i)<<','<<arr[i]<<endl;
    cout<<"value at index: "<<*(i+arr)<<','<<i[arr]<<endl; // same as above

    //char array

    char ch[6]="abcde";    // acts differnt than int array
    cout<<ch<<endl;     // prints entire string
    char *c= &ch[0];
    cout<<c<<endl;      // prints entire string

    // Double Pointers
    char **c1= &c;
    cout<<*c1<<endl;

    // reference variable - same memory different names
    i=5;
    int &k=i;
    cout<<i<<endl;
    i++;
    cout<<k<<endl;
    k++;
    cout<<i<<endl;
    // Reverse string
    int l=sizeof(ch);
    int s=0;
    int e=l-1-1;  // bcoz of '\0' at ch[6]
    while(s<e){
        swap(ch[s++],ch[e--]);
    }
    cout<<ch<<endl;

    // Reverse the string word wise
    string st="My name is Arvind";
    l=st.size();
    s=0;
    e=l;
    int te=-2;
    while(s<=e){
        if(st[s]==' ' || st[s]=='\0'){
            int ts=te+2;
            te=s-1;
            int i=ts;
            int j=te;
            while(i<j){
                swap(st[i++],st[j--]);
            }
        }
        s++;
    }cout<<st<<endl;

    // occurences of each character in string
    int arr1[26]={0};
    s=0;
    while(s<l){
        char cr=st[s];
        if(cr>='a' && cr<='z'){   //lowercase
            arr1[cr-'a']+=1;
        }
        if(cr>='A' && cr<='Z'){    // uppercase
            arr1[cr-'A']+=1;
        }
        s++;
    }
    for(int i:arr1){
        cout<<i<<" ";
    }cout<<endl;

    // getline function for to take multiple words
    /*
    int len;
    char str[len]; 
    cin.getline(str,len,'$');   // delimiter '$' is used to terminate taking input when it is encounter 
    */
     
     // replace ' ' by '@40'
    for(i=0;st[i]!='\0';i++){
        if(st[i]==' '){
            st.push_back(' ');
            st.push_back(' ');
            for(int j=st.size()-2;j!=i;j--){       
                st[j+1]=st[j-1];
                st[j]=st[j-2];
            }
            st[i]='@';
            st[i+1]='4';
            st[i+2]='0';
           
        }
        cout<<st[i];
    }cout<<endl;


    // remove all occurences of substring
    string substr="@40";
    while(st.length()!=0 && st.find(substr)<st.length()){
        int p=st.find(substr);
        st[p]=' ';
        st.erase(p+1,substr.length()-1);
    }
    cout<<st<<endl;

    // permutation of substring present in string or not
    string st1="ab";
    string st2="abaababbbbcaab";
    auto check=[](int arr1[],int arr2[]){
        for(int i=0;i<26;i++){
            if(arr1[i]!=arr2[i]){
                return 0;
            }
        }return 1;
    };
    int count1[26]={0};
    for(i=0;i<st1.length();i++){
        count1[st1[i]-'a']++;
    }
    int windowsize = st1.length();
    int count2[26]={0};
    int j=0;
    while(j<windowsize && j<st2.length()){ // create window & run 1st window 
        count2[st2[j]-'a']++;
        j++;
    }
    if(check(count1,count2)){
        cout<<st1<<" is present in "<<st2<<endl;
        goto jump;
    }
    while(j<st2.length()){  // aage window process karo
        count2[st2[j]-'a']++;
        count2[st2[j-windowsize]-'a']--;
        if(check(count1,count2)){
            cout<<st1<<" is present in "<<st2<<endl;
            break;
        }
        else if(j==st2.length()-1){
            cout<<st1<<" is not present in "<<st2<<endl;
        }
        j++;
    }
    jump:

    // Remove all adjacent duplicates in string
    l=st2.length();
    int t=1;
    while(t){
        t=0;
        for(i=0;i<l-1;i++){
            if(st2[i]==st2[i+1]){
                st2.erase(i,2);
                t=1;
            }
        }
    }
    cout<<st2<<endl;

    // string compressor
    st2="abaababbbbcaab";
    int count=1;
    string str;
    l=st2.length();
    for(i=0;i<l;i++){
        if(st2[i]==st2[i+1]){
            count++;
        }
        else{
            str.push_back(st2[i]);
            if(count>1){
                str.push_back('0' + count);  // to push int into string use '0' 
            }   
            count=1;
        }
    }
    cout<<str<<endl;
    // int to str ; str to int
    int o=123;
    string v=to_string(o);
    // v='0'+ o;
    cout<<v+"upp"<<endl;
    o=stoi(v);
    cout<<o<<endl;
    // print each word separately
    string s1="myNameIsArvind";
    l=s1.length();
    i=0;
    while(i<l){
        if(s1[i]<97){
            cout<<'\n';
            cout<<s1[i];
        }
        else{
            cout<<s1[i];
        }
        i++;
    }cout<<endl;
    // password checking
    string passw="Arvind@12212";
    l=passw.length();
    int ans=0;
    if(l<6 && l>22){
        ans++;
    }
    int C=0;
    s=0;
    int sc=0;
    int d=0;
    for(i=0;i<l;i++){
        if(passw[i]>=65 && passw[i]<=90){ //capital
            C=1;
        }
        if(C==0 && i==l-1){
            ans++;
        }
        if(passw[i]>=97 && passw[i]<=122){ //smallcase
            s=1;
        }
        if(s==0 && i==l-1){
            ans++;
        }
        if(isalnum(passw[i])==0){ // 2 special characters
            sc++;
        }
        if(i==l-1 && sc<2){
            ans++;
        }
        if(isdigit(passw[i])){ // numerical value
            d=1;
        }
        if(i==l-1 && d==0){
            ans++;
        }
        if(passw[i]==passw[i+1] && i<l-1){ // 2 consecutive letters should be unique
            ans++;
        }
    }
    cout<<ans<<endl;
    // team of 4 members with 1 experienced and 1 fresher
    int ex=10;
    int ue =14;
    int tm=ex+ue;
    int tms=0;
    while(tm>3){
        ex-=2;
        ue-=2;
        tm-=4;
        tms++;
    }
    cout<<tms<<endl;
    return 0;
}