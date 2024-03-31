#include <iostream>
using namespace std;
int fact(int n);//function prototype  //int fact(int); -another way
int main(){
   //int m;
   //cout<<"enter no. to find factorial of it: ";
   //cin>>m;
    cout<<fact(5);
}
int fact(int n){
    if (n==1 || n==0)
    return 1;
    else
   return n*fact(n-1);
}