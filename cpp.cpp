# include <iostream>  //system header file
# include<iomanip>
// # include "this.h"  -->user defined header file
// #include "cpp.cpp"  --> to add "cpp.cpp" file
using namespace std;
/* multiline 
  comment */
  int r=3;    //global variable
//function
int area1(int l,int br){       //l and br are formal parameters
        cout<<"area:"<<l*br<<endl;
        return 0;
}
int main()
{   
    int a;  
    a=12;
    cout<<"size of int is: "<<sizeof(a)<<endl;  /*'<<' is called insertion operator*/
    float p;
    cout<<"size of float is: "<<sizeof(p)<<endl;
    char c;
    cout<<"size of char is: "<<sizeof(c)<<endl;
    bool d;
    cout<<"size of bool is: "<<sizeof(d)<<endl;
    // if else if loop
    if(a>=13){
        cout<<"a is greater than 13"<<endl;
    }else if(a<10){
        cout<<"a is less than 10"<<endl;
    }else
        cout<<"a is between 10 and 13"<<endl;
    // for loop
    for(int i=1;i<5;i++){
        for(int j=1;j<5;j++){
            if(i==1||j==1||i==4||j==4){
            cout<<'*';}
            else
                cout<<" ";
        }cout<<endl;
    }
    // while loop
    int n=4;
    int count=1;
    // cin>>n;         /*'>>' extraction operator*/
    int i=n;
    while(i>0){
        for(int j=i;j>0;j--){
            cout<<count;     // floyd triangle
            count+=1;
        }cout<<endl;
    i--;
    }
    // do while loop
    i=1;
    do{ 
        for(int j=i;j>0;j--){
            cout<<'*';
        }cout<<endl;
        i++;
    }while(i<5);
    n=4;
    for(i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<i){
                cout<<" ";
            }
            else cout<<"*";
        }cout<<endl;
    }
    // Break statement
    n=5;
    for(int i=2;i<n;i++){
        if (n%i==0){
            cout<<"non prime"<<endl;
            break;
        }
    }
    if(i==n){
    cout<<n<<" is a prime number!"<<endl;}
    // Continue
    i=0;
    for(;i<=4;i++){
        if(i==2){
            continue;}
        cout<<i<<endl;
    }
    // switch case
    n=9;
    switch(n)
    {
    case 1:
        cout<<"good morning"<<endl;
        break;
    case 2:
        cout<<"good afternooon"<<endl;
        break;
    case 3:
        cout<<"good evening"<<endl;
        break;
    default:
        cout<<"wrong input"<<endl;
    }
    a=2;
    cout<<a++<<endl;   // post incrementor
    cout<<a<<endl;
    cout<<++a<<endl;     // pre incrementor
    // bitwise operator
    a=12;  //(1100)
    int b=10;  //1010
    cout<<(a & b)<<endl;  //and
    cout<<(a | b)<<endl;  //or
    cout<<(a ^ b)<<endl;  //xor
    cout<<(~ b)<<endl;   //ones complement
    cout<<(b << 1)<<endl;   // (b*2^n) left swift each bit by 1 position
    cout<<(b >> 2)<<endl;   // returns (b/2^n)
    //miscellaneous operator
    char u='a';
    cout<<sizeof(u)<<endl;    //sizeof()
    int x=1,y=2;
    int z=x>y?x-y:y-x;        //ternary/conditional operator
    cout<<z<<endl;
    char ch='a';
    cout<<int(ch)<<endl;    //cast
    a=(2,3,4);
    cout<<a<<endl;    // Comma :returns last value 
    cout<<&a<<endl;   //reference:address of a
    int *o=&a;    //'*'-> value at
    cout<<o<<endl;
    //function call
    int g=10;int h=9;
    area1(g,h);    //g and h are actual parameters
    //Array
    int arr[5]={2,5,3,7,-8};
    int max=0;
    for(i=0;i<5;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }cout<<"max: "<<max<<endl;
    //linear search
    int key=5;
    // int arr[5]={2,5,3,7,-8};
    for(i=0;i<5;i++){
        if(arr[i]==key){
            cout<<i+1<<endl;
        }
    }
    //character array
    char cha[100]={"arvind patel"};
    cout<<cha<<endl;
    int k=0;
    while(cha[k]!='\0'){   //iterate till null(\0) character encounters
        cout<<cha[k];
        k++;
    }cout<<endl;
    //access global var ,even local is given precedence
    float r=2.8;
    cout<<r<<"\n"<<::r<<endl;  // (local)r =2 and (global)::r =3
    /* bydefault decimal number is taken as double but if we have to pass
       float no. than 'f' or 'F' is written after no. ,eg:- 39.7f or 39.7F
       and 'l' or 'L' for long double.*/
    // typecasting
    cout<<"value of r:"<<int(r)<<"\n"<<(int)r<<endl;
    //constants
    const int v=90;
    // v=89;    // gives error that v is read-only variable 
    //manipulator  //header file <iomanip> ; endl is also a manipulator 
    int f=2,t=67,l=4567;
    cout<<"u:"<<setw(4)<<f<<endl;  //  for right justify
    cout<<"i:"<<setw(4)<<t<<endl;
    cout<<"d:"<<setw(4)<<l<<endl;
}
